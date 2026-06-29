# XMUOJ AI Helper (Auto Submitter TUI)

[English](#english) | [中文说明](#中文说明)

---

<h2 id="english">English</h2>

A powerful, interactive TUI (Text User Interface) tool that uses AI to automatically solve and submit competitive programming problems to [xmuoj.com](https://xmuoj.com).

### Features

- 🖥️ **Interactive TUI**: Easy-to-use menu to navigate between single problems and contests.
- 🤖 **AI-Powered Code Generation**: Uses OpenAI-compatible APIs to write code in Python3, C++, C, or Java.
- 🔁 **Auto-Retry & Self-Correction**: If the submitted code gets a `Wrong Answer` or `Compile Error`, the AI automatically reads the error and fixes its own code!
- 📚 **Contest Support**: Batch select problems in a contest. Automatically skips already `Accepted` problems!
- ⏰ **Human / Machine Modes**:
  - **Human Mode**: Respects your sleep schedule (avoids rest times) and pauses for a random 3~5 minutes between submissions to simulate a human pacing.
  - **Machine Mode**: Solves relentlessly 24/7 with strict 3-minute intervals.
- 💾 **Login & Cookie Caching**: Logs in once and saves your session to avoid repeated logins.
- 🎨 **Custom Code Styling**: Instructs the AI to follow strict styling guidelines (e.g. Chinese comments, snake_case). Edit `prompt_instruction.md` to tweak prompt rules!

### Setup

1. **Clone the repository & Setup virtual environment**:
```bash
python3 -m venv venv
./venv/bin/pip install -r requirements.txt
```

2. **Configure your credentials**:
Rename `config.example.json` to `config.json` and fill in your details:
```json
{
  "username": "YOUR_XMUOJ_USERNAME",
  "password": "YOUR_XMUOJ_PASSWORD",
  "api_key": "YOUR_AI_API_KEY",
  "base_url": "YOUR_API_BASE_URL",
  "model": "YOUR_MODEL_NAME",
  "language": "Python3"
}
```

### Usage

Simply run the interactive TUI:
```bash
./venv/bin/python tui.py
```

### Modes & Settings
You can modify the timing configuration directly through the TUI by selecting the **`Settings (配置时间策略)`** option in the main menu!

---

<h2 id="中文说明">中文说明</h2>

一个强大的交互式 TUI 终端工具，利用 AI（大语言模型）全自动地为 [xmuoj.com](https://xmuoj.com) 刷题、写代码并提交。

### ✨ 核心功能

- 🖥️ **交互式 TUI 界面**：支持终端菜单选择，告别繁琐的命令行参数，轻松选择单题或比赛模式。
- 🤖 **AI 全自动写代码**：接入 OpenAI 兼容格式的 API（支持 ChatGPT、DeepSeek、Gemini 等），自动识别题目要求并编写 Python3 / C++ / C / Java 代码。
- 🔁 **错误自愈与自动重试**：提交后如果遭遇 `Wrong Answer` (答案错误) 或 `Compile Error` (编译错误)，AI 会自动读取系统的报错输出，并自己修改错误代码重新提交！
- 📚 **Contest 比赛支持**：支持直接输入比赛 ID 和密码进入比赛。**自动跳过你已经 AC 的题目**，提供交互式多选框（空格勾选、`a` 全选、`i` 反选）。
- ⏰ **人类 / 机器双模式挂机**：
  - **人类模式**：智能避开防沉迷作息时间（如凌晨、中午、傍晚自动暂停），并在非休息时间段通过 3~5 分钟的随机间隔提交，完美模拟人类做题速度。
  - **机器模式**：24小时无情刷题，精准固定每 N 分钟做一题。
- 💾 **Cookie 会话缓存**：首次登录后自动缓存 Session，拒绝频繁登录触发系统风控。
- 🎨 **可定制的代码规范**：你可以随时编辑根目录下的 `prompt_instruction.md` 文件。想要加注释？想要限定变量命名风格？直接用文字写在里面，AI 做题时会自动严格遵守。

### 🚀 快速开始

1. **拉取项目并配置虚拟环境**:
```bash
python3 -m venv venv
./venv/bin/pip install -r requirements.txt
```

2. **配置账号信息**:
将 `config.example.json` 复制或重命名为 `config.json`，并填入你的账号密码及 API 密钥：
```json
{
  "username": "你的用户名/学号",
  "password": "你的密码",
  "api_key": "你的_AI_API_KEY",
  "base_url": "你的大模型接口地址",
  "model": "调用的模型名(例如: gemini-1.5-pro)",
  "language": "Python3"
}
```

### 🎮 如何使用

在终端直接运行以下命令进入交互式主界面：
```bash
./venv/bin/python tui.py
```

### ⚙️ 设置与调整
你完全不需要修改底层代码，只需直接在 TUI 主菜单中选择 **`Settings (配置时间策略)`**，即可通过交互式问答在终端内随时调整两种模式的间隔时间与休息时段！
