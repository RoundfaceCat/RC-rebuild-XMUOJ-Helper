import questionary
from rich.console import Console
from rich.panel import Panel
from rich.progress import SpinnerColumn, TextColumn, Progress
import sys
import time
import datetime
from .xmuoj_bot import XMUOJBot, load_config, ask_ai_for_code
import random
console = Console()

import json
def parse_time(time_str):
    h, m = map(int, time_str.split(':'))
    return datetime.time(h, m)

def is_rest_time(now, config):
    rest_str = config.get("rest_times", "01:00-08:00, 12:00-13:00, 18:00-19:00")
    t = now.time()
    
    for period in rest_str.split(','):
        period = period.strip()
        if not period: continue
        try:
            start_str, end_str = period.split('-')
            start_t = parse_time(start_str.strip())
            end_t = parse_time(end_str.strip())
            
            if start_t <= t < end_t:
                wake = datetime.datetime.combine(now.date(), end_t)
                return True, (wake - now).total_seconds()
        except:
            pass
    return False, 0

def enforce_schedule(config, is_first=False, mode="Human"):
    if mode == "Human":
        while True:
            now = datetime.datetime.now()
            resting, sleep_sec = is_rest_time(now, config)
            if resting:
                wake_time = now + datetime.timedelta(seconds=sleep_sec)
                console.print(f"\n[bold yellow]💤 [休息时间] 当前是休息时间段，程序将暂停至 {wake_time.strftime('%H:%M:%S')}。[/bold yellow]")
                time.sleep(sleep_sec)
            else:
                break
                
        if not is_first:
            min_val = float(config.get("human_interval_min", 3))
            max_val = float(config.get("human_interval_max", 5))
            sleep_minutes = random.uniform(min_val, max_val)
            sleep_sec = int(sleep_minutes * 60)
            console.print(f"\n[cyan]⏳ 人类模式: 等待 {sleep_sec} 秒（约 {sleep_minutes:.1f} 分钟）后开始处理下一题...[/cyan]")
            time.sleep(sleep_sec)
    else:
        if not is_first:
            sleep_sec = int(config.get("machine_interval", 180))
            console.print(f"\n[cyan]🤖 机器模式: 等待 {sleep_sec} 秒（{sleep_sec//60} 分钟）后开始处理下一题...[/cyan]")
            time.sleep(sleep_sec)

def solve_single_problem(bot, problem_data, config, contest_id=None):
    title = problem_data.get('title', 'Unknown')
    display_id = problem_data.get('_id', str(problem_data.get('id')))
    internal_id = problem_data.get('id')
    console.print(f"\n[bold cyan]Starting to solve:[/bold cyan] {display_id} - {title}")
    
    max_retries = 3
    error_feedback = ""
    language = config.get("language", "Python3")
    
    for attempt in range(max_retries):
        if attempt > 0:
            console.print(f"[yellow]Retry {attempt}/{max_retries - 1} based on previous error...[/yellow]")
            
        with Progress(SpinnerColumn(), TextColumn("[progress.description]{task.description}"), transient=True) as progress:
            progress.add_task(description=f"Asking AI ({config['model']}) to write {language} code...", total=None)
            code = ask_ai_for_code(problem_data, config['api_key'], config.get('base_url'), config['model'], language, error_feedback, api_proxy=config.get('api_proxy', 'http://127.0.0.1:7890'))
            
        if not code:
            console.print("[red]AI generation failed or returned nothing.[/red]")
            break
            
        console.print(Panel(code, title="AI Generated Code", subtitle=language))
        
        submission_id = bot.submit_code(internal_id, language, code, contest_id)
        if submission_id:
            status, status_text, info = bot.check_submission_status(submission_id)
            if status == 0:  # Accepted
                console.print("[bold green]🚀 Problem solved successfully (Accepted)![/bold green]")
                return True
            else:
                console.print(f"[bold red]❌ Failed: {status_text}[/bold red]")
                error_feedback = f"Your previous submission returned: {status_text}.\n"
                if info:
                    error_feedback += f"Error details/output: {info}\n"
                error_feedback += f"\nThe code you previously submitted was:\n```\n{code}\n```\nPlease carefully fix the errors and try again."
        else:
            break
            
    console.print("[red]Failed to solve after maximum retries.[/red]")
    return False

def configure_settings(config):
    console.print("\n[bold cyan]--- 全局设置 (Global Settings) ---[/bold cyan]")
    
    # Credentials
    username = questionary.text("XMUOJ 用户名/学号:", default=config.get("username", "")).ask()
    password = questionary.password("XMUOJ 密码:", default=config.get("password", "")).ask()
    
    # API Config
    api_key = questionary.text("AI API Key:", default=config.get("api_key", "")).ask()
    base_url = questionary.text("AI Base URL (例如 https://api.openai.com/v1):", default=config.get("base_url", "https://api.openai.com/v1")).ask()
    model = questionary.text("AI 模型名称 (例如 gpt-4o 或 gemini-1.5-pro):", default=config.get("model", "gemini-1.5-pro")).ask()
    language = questionary.select("提交语言 (OJ 支持的语言):", choices=["Python3", "C++", "C", "Java"], default=config.get("language", "Python3")).ask()
    api_proxy = questionary.text("AI API Proxy 代理地址 (留空则不使用):", default=config.get("api_proxy", "http://127.0.0.1:7890")).ask()

    console.print("\n[bold cyan]--- 策略时间配置 ---[/bold cyan]")
    human_min = questionary.text("人类模式 - 最小间隔时间 (分钟):", default=str(config.get("human_interval_min", 3))).ask()
    human_max = questionary.text("人类模式 - 最大间隔时间 (分钟):", default=str(config.get("human_interval_max", 5))).ask()
    machine_sec = questionary.text("机器模式 - 固定间隔时间 (秒):", default=str(config.get("machine_interval", 180))).ask()
    
    default_rest = config.get("rest_times", "01:00-08:00, 12:00-13:00, 18:00-19:00")
    rest_times_str = questionary.text("防沉迷休息时段 (格式 HH:MM-HH:MM, 逗号分隔):", default=default_rest).ask()
    
    if any(x is None for x in [username, password, api_key, base_url, model, language, api_proxy, human_min, human_max, machine_sec, rest_times_str]):
        return config # Cancelled
        
    config["username"] = username
    config["password"] = password
    config["api_key"] = api_key
    config["base_url"] = base_url
    config["model"] = model
    config["language"] = language
        
    config["human_interval_min"] = float(human_min)
    config["human_interval_max"] = float(human_max)
    config["machine_interval"] = int(machine_sec)
    config["rest_times"] = rest_times_str
    if api_proxy:
        config["api_proxy"] = api_proxy
    elif "api_proxy" in config:
        del config["api_proxy"]
    
    with open('config.json', 'w', encoding='utf-8') as f:
        json.dump(config, f, indent=2)
    console.print("[green]✅ 配置已保存到 config.json![/green]\n")
    return config

def main():
    console.print(Panel.fit("[bold blue]XMUOJ AI Auto Submitter TUI[/bold blue]", border_style="blue"))
    
    config = load_config()
    
    if not config.get('username') or not config.get('password') or not config.get('api_key'):
        console.print("[yellow]检测到尚未配置必要信息，进入首次设置向导...[/yellow]")
        config = configure_settings(config)
        if not config.get('username') or not config.get('password') or not config.get('api_key'):
            console.print("[red]配置未完成，程序退出。[/red]")
            sys.exit(1)
        
    bot = XMUOJBot(config['username'], config['password'])
    if not bot.login():
        sys.exit(1)
        
    while True:
        action = questionary.select(
            "What do you want to do?",
            choices=[
                "Solve a Single Problem",
                "Solve a Contest",
                "Settings (全局设置)",
                "Exit"
            ]
        ).ask()
        
        if action == "Exit" or not action:
            sys.exit(0)
            
        elif action == "Settings (全局设置)":
            config = configure_settings(config)
            continue
            
        if action == "Solve a Single Problem":
            prob_id = questionary.text("Enter Problem Display ID (e.g., GW001):").ask()
            if not prob_id: continue
            problem_data = bot.get_problem(prob_id)
            if problem_data:
                solve_single_problem(bot, problem_data, config)
            break
            
        elif action == "Solve a Contest":
            contest_id = questionary.text("Enter Contest ID (e.g., 359):").ask()
            if not contest_id: continue
            
            password = questionary.password("Enter Contest Password (leave blank if none):").ask()
            
            problems = bot.get_contest_problems(contest_id, password)
            if not problems:
                continue
                
            choices = []
            for p in problems:
                status_text = ""
                if p.get("my_status") == 0:
                    status_text = " [已通过/AC]"
                elif p.get("my_status") is not None:
                    status_text = " [尝试过/未通过]"
                    
                display = f"{p.get('_id')} - {p.get('title')}{status_text}"
                
                # Default to checked if not passed
                is_checked = (p.get("my_status") != 0)
                choices.append(questionary.Choice(title=display, value=p, checked=is_checked))
                
            selected_problems = questionary.checkbox(
                "Select problems to solve (空格: 选择, 回车: 确认, 'a': 全选, 'i': 反选):",
                choices=choices
            ).ask()
            
            if not selected_problems:
                console.print("[yellow]No problems selected.[/yellow]")
                continue
                
            mode_choice = questionary.select(
                "Select solving mode:",
                choices=[
                    questionary.Choice("人类模式 (Human Mode) - 避开作息时间，随机间隔 3-5 分钟", "Human"),
                    questionary.Choice("机器模式 (Machine Mode) - 全天候运行，固定间隔 3 分钟", "Machine")
                ]
            ).ask()
            
            if not mode_choice:
                continue
                
            for i, p in enumerate(selected_problems):
                if p.get("my_status") == 0:
                    console.print(f"\n[bold green]=== Skipping Problem {p.get('_id')} (Already Accepted) ===[/bold green]")
                    continue
                    
                enforce_schedule(config, is_first=(i == 0), mode=mode_choice)
                console.print(f"\n[bold magenta]=== Processing Problem {i+1}/{len(selected_problems)} ==-[/bold magenta]")
                # For contests, the problem object returned by the list API might not have the full description
                # We need to fetch the full details
                full_problem = bot.get_contest_problem_details(p.get('_id'), contest_id)
                if full_problem:
                    solve_single_problem(bot, full_problem, config, contest_id=contest_id)
                else:
                    console.print(f"[red]Failed to fetch details for {p.get('_id')}[/red]")
            
            break # Exit the while loop after solving a contest or problem


if __name__ == "__main__":
    main()
