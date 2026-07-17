# XMUOJ AI Helper (Auto Submitter & AI Agent Framework)

[English](#english) | [中文说明](#中文说明)

---

<h2 id="english">English</h2>

A powerful tool and standard AI workflow framework designed to automatically solve and submit competitive programming problems to [xmuoj.com](https://xmuoj.com) using AI Agents.

### 🌟 New: Agentic Workflow & Auto-Solver Framework
This project has been heavily upgraded to act as an **Automated AI Factory**:
- 📂 **Dual-Directory Pipeline**: All generated solutions are written to `answers/pending/` for testing. Upon a successful `Accepted` judgment from the OJ, the script automatically archives the pure code to `answers/correct/`.
- 🤖 **Universal AI SOP**: Included `AI_SOP.md` at the project root. You can drop any modern LLM (ChatGPT, Claude Code, Grok, Cursor, Windsurf) into this repository and tell it to read `AI_SOP.md`. The AI will instantly understand how to request permissions, write memory-optimized C++ code, submit, and self-heal from WA/PA errors up to 3 times without human intervention.
- 🚀 **Native Antigravity Skill**: If you are using the Antigravity Agent, the project includes a native `.agents/skills/xmuoj-auto-solver` skill. Simply mention "Solve JDxxx" and the agent will automatically request batch permissions and enter a fully autonomous, silent execution loop.

### 💻 Legacy / Manual Features
- 🖥️ **Interactive TUI**: Run `python tui.py` for an easy-to-use menu to navigate between single problems and contests.
- 🔁 **Command Line Bot (`xmuoj_bot.py`)**: 
  - `--mode extract`: Scrapes problem descriptions and formatting them into `problems.md`.
  - `--mode submit`: Batch submits all local C/C++/Python files inside `answers/pending/`.
- ⏰ **Human / Machine Modes**: Built-in pacing algorithms to simulate human submission intervals and respect sleep schedules.
- 🎨 **Custom Code Styling**: The AI follows strict rules (e.g. Chinese comments, snake_case) defined in `prompt_instruction.md`.

### Setup
1. **Virtual Environment**:
   ```powershell
   # Windows
   python -m venv venv
   .\venv\Scripts\pip install -r requirements.txt
   ```
2. **Configuration**:
   Copy `config.example.json` to `config.json` and fill in your XMUOJ and AI API credentials.

---

<h2 id="中文说明">中文说明</h2>

一个强大的 XMUOJ 自动化刷题框架。不仅包含交互式终端工具，还深度集成了 **Agentic（智能体）自动化流水线**，让任何主流 AI 都能零基础接管您的刷题任务。

### 🌟 全新特性：智能体全自动刷题工厂
本项目已重构为面向 AI Agent 的标准工作流框架：
- 📂 **双轨制目录架构**：AI 编写的草稿代码统一落于 `answers/pending/`。当终端脚本探测到判题结果为 `Accepted` 时，会自动将其提拔、归档至 `answers/correct/` 荣誉满分库。
- 🤖 **全平台通用 AI SOP (`AI_SOP.md`)**：项目根目录自带标准操作说明书。无论您使用 Cursor、Claude Code、Grok 还是普通 GPT，只需让其阅读此文件，它便能瞬间领悟：如何获取题目、为何必须用 C++ 规避内存溢出、如何执行提交脚本、并在遇到 WA (答案错误) 时自行扒取日志修改重试，全程无需人类插手。
- 🚀 **反重力专属原生技能 (Antigravity Skill)**：内置于 `.agents` 目录。当使用 Antigravity 智能体时，只需说一句“帮我做 JDxxx”，它会自动触发该技能，一次性索要全部必要权限并进入无人值守的挂机死循环，直至题目 AC。

### 💻 经典终端功能
- 🖥️ **交互式 TUI 界面**：运行 `python tui.py` 即可进入控制台菜单，轻松配置刷题策略。
- 🔁 **核心驱动脚本 (`xmuoj_bot.py`)**：
  - 执行 `--mode extract`：自动抓取在线题库并排版保存至 `problems.md`。
  - 执行 `--mode submit`：一键将 `pending/` 目录下的代码全部发往 OJ 判题。
- ⏰ **人类 / 机器双模式挂机**：可智能避开防沉迷作息时间，并通过随机间隔提交完美模拟人类行为。。
- 🎨 **代码规范约束**：根目录下的 `prompt_instruction.md` 强制约束了所有 AI 生成代码的注释风格（中文）和变量命名规则。

### 🚀 快速开始
1. **配置环境**:
   ```powershell
   # Windows 用户
   python -m venv venv
   .\venv\Scripts\pip install -r requirements.txt
   ```
2. **账号配置**:
   将 `config.example.json` 重命名为 `config.json`，并填入您的 OJ 账号密码及大模型 API Key。
