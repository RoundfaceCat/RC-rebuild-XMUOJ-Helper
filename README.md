# XMUOJ AI Helper (Auto Submitter TUI)

A powerful, interactive TUI (Text User Interface) tool that uses AI to automatically solve and submit competitive programming problems to [xmuoj.com](https://xmuoj.com).

## Features

- 🖥️ **Interactive TUI**: Easy-to-use menu to navigate between single problems and contests.
- 🤖 **AI-Powered Code Generation**: Uses OpenAI-compatible APIs to write code in Python3, C++, C, or Java.
- 🔁 **Auto-Retry & Self-Correction**: If the submitted code gets a `Wrong Answer` or `Compile Error`, the AI automatically reads the error and fixes its own code!
- 📚 **Contest Support**: Batch select problems in a contest. Automatically skips already `Accepted` problems!
- ⏰ **Human / Machine Modes**:
  - **Human Mode**: Respects your sleep schedule (avoids rest times) and pauses for a random 3~5 minutes between submissions to simulate a human pacing.
  - **Machine Mode**: Solves relentlessly 24/7 with strict 3-minute intervals.
- 💾 **Login & Cookie Caching**: Logs in once and saves your session to avoid repeated logins.
- 🎨 **Custom Code Styling**: Instructs the AI to follow strict styling guidelines (e.g. Chinese comments, snake_case). Edit `prompt_instruction.md` to tweak prompt rules!

## Setup

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

## Usage

Simply run the interactive TUI:
```bash
./venv/bin/python tui.py
```

### Modes & Settings
You can modify the timing configuration directly through the TUI by selecting the **`Settings (配置时间策略)`** option in the main menu!
