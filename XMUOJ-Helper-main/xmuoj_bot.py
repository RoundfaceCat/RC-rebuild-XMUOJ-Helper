import argparse
import json
import os
import shutil
import time
import urllib3
import requests
from bs4 import BeautifulSoup
from openai import OpenAI

# Disable InsecureRequestWarning since the site's cert might be expired
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

# QDUOJ standard status codes
STATUS_MAP = {
    -2: "Compile Error",
    -1: "Wrong Answer",
     0: "Accepted",
     1: "Time Limit Exceeded",
     2: "Time Limit Exceeded",
     3: "Memory Limit Exceeded",
     4: "Runtime Error",
     5: "System Error",
     6: "Pending",
     7: "Judging",
     8: "Partial Accepted",
     9: "Submitting"
}

class XMUOJBot:
    def __init__(self, username, password, base_oj_url="https://xmuoj.com"):
        self.username = username
        self.password = password
        self.base_oj_url = base_oj_url.rstrip('/')
        self.session = requests.Session()
        
        if os.path.exists('cookies.json'):
            try:
                with open('cookies.json', 'r') as f:
                    cookies = json.load(f)
                    self.session.cookies.update(cookies)
            except Exception:
                pass
        
    def _request(self, method, endpoint, **kwargs):
        url = f"{self.base_oj_url}{endpoint}"
        kwargs.setdefault('verify', False)
        
        if method.upper() in ["POST", "PUT"]:
            # Need CSRF token for state-changing requests
            if 'csrftoken' not in self.session.cookies:
                self.session.get(f"{self.base_oj_url}/api/profile", verify=False)
            
            headers = kwargs.get('headers', {})
            headers['X-CSRFToken'] = self.session.cookies.get_dict().get('csrftoken')
            kwargs['headers'] = headers
            
            # Referer is also checked by Django CSRF
            headers['Referer'] = self.base_oj_url
            
        res = self.session.request(method, url, **kwargs)
        try:
            return res.json()
        except json.JSONDecodeError:
            print("Failed to decode JSON. Response text:")
            print(res.text)
            return None

    def login(self):
        print("[*] Checking login status...")
        res_profile = self._request("GET", "/api/profile")
        if res_profile and res_profile.get("data"):
            print("[+] Already logged in via cached session!")
            return True
            
        print("[*] Cache missed or invalid. Attempting to login...")
        res = self._request("POST", "/api/login", json={
            "username": self.username,
            "password": self.password
        })
        if res and res.get("error") is None:
            print("[+] Login successful!")
            try:
                with open('cookies.json', 'w') as f:
                    json.dump(self.session.cookies.get_dict(), f)
            except Exception as e:
                print(f"[-] Warning: Failed to save cookies: {e}")
            return True
        else:
            print("[-] Login failed:", res.get("data") if res else "Unknown error")
            return False

    def get_problem(self, display_id):
        print(f"[*] Fetching problem details for {display_id}...")
        res = self._request("GET", f"/api/problem?problem_id={display_id}")
        if res and res.get("error") is None:
            data = res.get("data")
            print(f"[+] Found problem: {data.get('title')}")
            return data
        else:
            print("[-] Failed to fetch problem:", res.get("data") if res else "Unknown error")
            return None

    def get_contest_problems(self, contest_id, password=None):
        print(f"[*] Fetching problems for contest {contest_id}...")
        if password:
            res_pass = self._request("POST", "/api/contest/password", json={
                "contest_id": int(contest_id),
                "password": password
            })
            if res_pass and res_pass.get("error"):
                print("[-] Contest password verification failed:", res_pass.get("data"))
                return None
                
        res = self._request("GET", f"/api/contest/problem?contest_id={contest_id}")
        if res and res.get("error") is None:
            data = res.get("data")
            print(f"[+] Found {len(data)} problems in contest.")
            return data
        else:
            print("[-] Failed to fetch contest problems:", res.get("data") if res else "Unknown error")
            return None

    def get_contest_problem_details(self, display_id, contest_id):
        print(f"[*] Fetching contest problem details for {display_id}...")
        res = self._request("GET", f"/api/contest/problem?contest_id={contest_id}&problem_id={display_id}")
        if res and res.get("error") is None:
            data = res.get("data")
            return data
        else:
            print("[-] Failed to fetch contest problem details:", res.get("data") if res else "Unknown error")
            return None

    def submit_code(self, internal_id, language, code, contest_id=None):
        print(f"[*] Submitting code for problem internal ID {internal_id} in {language}...")
        payload = {
            "problem_id": internal_id,
            "language": language,
            "code": code
        }
        if contest_id:
            payload["contest_id"] = int(contest_id)
            
        while True:
            res = self._request("POST", "/api/submission", json=payload)
            if res and res.get("error") is None:
                submission_id = res.get("data", {}).get("submission_id")
                print(f"[+] Code submitted! Submission ID: {submission_id}")
                return submission_id
            else:
                data = res.get("data", "")
                if isinstance(data, str) and "Please wait" in data:
                    try:
                        # e.g., "Please wait 14 seconds"
                        seconds = int([s for s in data.split() if s.isdigit()][0])
                    except:
                        seconds = 15
                    print(f"[*] OJ Rate Limit: {data}. Sleeping {seconds + 1}s before retry...")
                    time.sleep(seconds + 1)
                    continue
                else:
                    print("[-] Submission failed:", data if res else "Unknown error")
                    return None

    def check_submission_status(self, submission_id):
        while True:
            res = self._request("GET", f"/api/submission?id={submission_id}")
            if not res or res.get("error"):
                print("[-] Failed to fetch submission status.")
                break
            
            data = res.get("data")
            status = data.get("result")
            status_text = STATUS_MAP.get(status, f"Unknown ({status})")
            
            if status in [6, 7, 9]: # Pending, Judging, Submitting
                print(f"[*] Status: {status_text}...")
                time.sleep(2)
            else:
                print(f"\n[=] Final Status: {status_text}")
                info = data.get("info", {})
                if status != 0:
                    print("--- Error Information ---")
                    if info:
                        print(info)
                    else:
                        print("No error details available.")
                return status, status_text, info

def strip_html(html_str):
    if not html_str: return ""
    soup = BeautifulSoup(html_str, "html.parser")
    return soup.get_text()

def ask_ai_for_code(problem_data, api_key, base_url, model, language, error_feedback=""):
    print(f"[*] Asking AI ({model}) to generate {language} code...")
    client = OpenAI(api_key=api_key, base_url=base_url)
    
    title = problem_data.get('title', '')
    desc = strip_html(problem_data.get('description', ''))
    input_desc = strip_html(problem_data.get('input_description', ''))
    output_desc = strip_html(problem_data.get('output_description', ''))
    hint = strip_html(problem_data.get('hint', ''))
    
    samples = problem_data.get('samples', [])
    samples_str = ""
    for idx, sample in enumerate(samples, 1):
        samples_str += f"Sample Input {idx}:\n{sample.get('input', '')}\nSample Output {idx}:\n{sample.get('output', '')}\n\n"
        
    try:
        with open('prompt_instruction.md', 'r', encoding='utf-8') as f:
            custom_instructions = f.read()
    except Exception:
        custom_instructions = ""
        
    prompt = f"""
Please solve the following competitive programming problem. 
Output ONLY valid {language} code without any markdown formatting or explanation. The code should read from standard input and write to standard output.

{custom_instructions}

Problem Title: {title}
Description: {desc}
Input Format: {input_desc}
Output Format: {output_desc}
Hint: {hint}

Samples:
{samples_str}
"""
    if error_feedback:
        prompt += f"\n\n--- FEEDBACK FROM PREVIOUS ATTEMPT ---\n{error_feedback}\n"
        prompt += "Please fix the code based on the feedback above and output the complete corrected code."
    try:
        response = client.chat.completions.create(
            model=model,
            messages=[{"role": "user", "content": prompt}],
            temperature=0.2,
        )
        code = response.choices[0].message.content.strip()
        # Remove markdown code blocks if the AI accidentally included them
        if code.startswith("```"):
            code = "\n".join(code.split("\n")[1:])
        if code.endswith("```"):
            code = "\n".join(code.split("\n")[:-1])
        return code.strip()
    except Exception as e:
        print("[-] AI generation failed:", str(e))
        return None

def load_config():
    if os.path.exists('config.json'):
        try:
            with open('config.json', 'r', encoding='utf-8') as f:
                return json.load(f)
        except Exception as e:
            print(f"[-] Failed to load config.json: {e}")
    return {}

def write_problem_to_md(problem_data, display_id, file_path):
    title = problem_data.get('title', '')
    desc = strip_html(problem_data.get('description', ''))
    input_desc = strip_html(problem_data.get('input_description', ''))
    output_desc = strip_html(problem_data.get('output_description', ''))
    hint = strip_html(problem_data.get('hint', ''))
    
    with open(file_path, 'a', encoding='utf-8') as f:
        f.write(f"# [{display_id}] {title}\n\n")
        f.write(f"## Description\n{desc}\n\n")
        if input_desc:
            f.write(f"## Input Format\n{input_desc}\n\n")
        if output_desc:
            f.write(f"## Output Format\n{output_desc}\n\n")
        if hint:
            f.write(f"## Hint\n{hint}\n\n")
            
        samples = problem_data.get('samples', [])
        for idx, sample in enumerate(samples, 1):
            f.write(f"### Sample {idx}\n")
            f.write(f"**Input:**\n```text\n{sample.get('input', '')}\n```\n")
            f.write(f"**Output:**\n```text\n{sample.get('output', '')}\n```\n\n")
        f.write("---\n\n")

def get_language_ext(language):
    language_lower = language.lower()
    if 'python' in language_lower: return '.py'
    if 'c++' in language_lower or 'cpp' in language_lower: return '.cpp'
    if 'c' == language_lower: return '.c'
    if 'java' in language_lower: return '.java'
    return '.txt'

def main():
    config = load_config()
    parser = argparse.ArgumentParser(description="XMUOJ AI Auto Submitter")
    parser.add_argument("--mode", choices=["auto", "extract", "submit"], default="auto", help="Mode: auto (default), extract (fetch to md), submit (batch submit)")
    parser.add_argument("--username", default=config.get("username"), help="Your XMUOJ username")
    parser.add_argument("--password", default=config.get("password"), help="Your XMUOJ password")
    parser.add_argument("--problem", help="Problem Display ID (e.g., GW001 or GW001,GW002)")
    parser.add_argument("--contest", help="Contest ID for batch processing")
    parser.add_argument("--contest-password", default=config.get("contest_password"), help="Password for contest if required")
    parser.add_argument("--language", default=config.get("language", "Python3"), help="Language to submit (e.g., Python3, C, C++, Java)")
    parser.add_argument("--api-key", default=config.get("api_key"), help="AI API Key")
    parser.add_argument("--base-url", default=config.get("base_url"), help="AI Base URL (Optional, for compatible APIs)")
    parser.add_argument("--model", default=config.get("model", "gpt-3.5-turbo"), help="AI Model to use")
    
    args = parser.parse_args()
    
    if not args.username or not args.password:
        print("[-] Error: Missing username or password.")
        return
        
    bot = XMUOJBot(args.username, args.password)
    if not bot.login():
        return
        
    # Gather problems based on arguments
    problems_to_process = []
    
    if args.contest:
        contest_data = bot.get_contest_problems(args.contest, args.contest_password)
        if not contest_data:
            return
        for item in contest_data:
            # QDUOJ API usually returns my_status = 0 for Accepted problems
            if item.get('my_status') == 0:
                print(f"[*] Skipping {item.get('_id')} (Already Accepted)")
                continue
            problems_to_process.append({
                'display_id': str(item.get('_id')),
                'internal_id': item.get('id'),
                'contest_id': args.contest
            })
    elif args.problem:
        prob_ids = args.problem.split(',')
        for pid in prob_ids:
            pid = pid.strip()
            if not pid: continue
            p_data = bot.get_problem(pid)
            if p_data:
                problems_to_process.append({
                    'display_id': pid,
                    'internal_id': p_data.get('id'),
                    'contest_id': None
                })
    else:
        print("[-] Error: Please specify either --problem or --contest")
        return

    if not problems_to_process:
        print("[-] No problems found to process.")
        return

    if args.mode == "extract":
        md_file = "problems.md"
        # Clear existing file
        with open(md_file, 'w', encoding='utf-8') as f:
            f.write(f"# XMUOJ Problems Extract\n\n")
            
        print(f"[*] Extracting {len(problems_to_process)} problems to {md_file}...")
        for p in problems_to_process:
            if p['contest_id']:
                p_data = bot.get_contest_problem_details(p['display_id'], p['contest_id'])
            else:
                p_data = bot.get_problem(p['display_id'])
                
            if p_data:
                write_problem_to_md(p_data, p['display_id'], md_file)
                print(f"[+] Appended {p['display_id']} to {md_file}")
        print(f"\n[+] Extract complete! Please solve them and put answers in 'answers/pending/' folder.")
        
    elif args.mode == "submit":
        pending_dir = os.path.join('answers', 'pending')
        correct_dir = os.path.join('answers', 'correct')
        os.makedirs(pending_dir, exist_ok=True)
        os.makedirs(correct_dir, exist_ok=True)
            
        ext = get_language_ext(args.language)
        print(f"[*] Batch submitting from '{pending_dir}/' for {len(problems_to_process)} problems...")
        for p in problems_to_process:
            ans_file = os.path.join(pending_dir, f"{p['display_id']}{ext}")
            if not os.path.exists(ans_file):
                ans_file_txt = os.path.join(pending_dir, f"{p['display_id']}.txt")
                if os.path.exists(ans_file_txt):
                    ans_file = ans_file_txt
                else:
                    print(f"[-] Skip {p['display_id']}: No file {ans_file} found.")
                    continue
                    
            with open(ans_file, 'r', encoding='utf-8') as f:
                code = f.read()
                
            submission_id = bot.submit_code(p['internal_id'], args.language, code, p['contest_id'])
            if submission_id:
                status, status_text, info = bot.check_submission_status(submission_id)
                if status == 0:
                    print(f"[+] [SUCCESS] {p['display_id']} Accepted!")
                    correct_file = os.path.join(correct_dir, os.path.basename(ans_file))
                    if os.path.exists(correct_file):
                        os.remove(correct_file)
                    shutil.move(ans_file, correct_file)
                    print(f"[+] Moved {os.path.basename(ans_file)} to '{correct_dir}/'")
                else:
                    print(f"[-] [FAILED] {p['display_id']} Failed: {status_text}")
                    if info:
                        print(f"[-] Error details/output:\n{info}")
        print("\n[*] Batch submit complete.")

    elif args.mode == "auto":
        if not args.api_key:
            print("[-] Error: Missing api_key for auto mode.")
            return
            
        for p in problems_to_process:
            print(f"\n================ Processing {p['display_id']} ================")
            if p['contest_id']:
                problem_data = bot.get_contest_problem_details(p['display_id'], p['contest_id'])
            else:
                problem_data = bot.get_problem(p['display_id'])
                
            if not problem_data: continue
                
            max_retries = 3
            error_feedback = ""
            for attempt in range(max_retries):
                if attempt > 0:
                    print(f"\n[*] Retry {attempt}/{max_retries - 1} based on previous error...")
                    
                code = ask_ai_for_code(problem_data, args.api_key, args.base_url, args.model, args.language, error_feedback)
                if not code:
                    break
                    
                print("\n[+] AI Generated Code:")
                print("-" * 40)
                print(code)
                print("-" * 40)
                
                submission_id = bot.submit_code(p['internal_id'], args.language, code, p['contest_id'])
                if submission_id:
                    status, status_text, info = bot.check_submission_status(submission_id)
                    if status == 0:  # Accepted
                        print(f"\n[+] [SUCCESS] {p['display_id']} solved successfully!")
                        break
                    else:
                        error_feedback = f"Your previous submission returned: {status_text}.\n"
                        if info:
                            error_feedback += f"Error details/output: {info}\n"
                        error_feedback += f"\nThe code you previously submitted was:\n```\n{code}\n```\nPlease carefully fix the errors and try again."
                        print(f"[-] AI failed on attempt {attempt + 1}. Will retry...")
                else:
                    break
                    
        print("\n[*] Auto process finished.")

if __name__ == "__main__":
    main()
