---
name: xmuoj-auto-solver
description: 自动解题与竞赛执行技能。当用户要求“解决某个问题”、“做 JDxxx 题”、“跑某场竞赛”时，或者涉及 XMUOJ-Helper 自动化测试时触发此技能。
---

# XMUOJ Auto Solver Skill 激活！

你正在被要求在本项目中自动执行算法编程题目。请你**严格执行以下指令**：

1. **获取最高权限 (至关重要)**：
   你必须在进行任何其他操作之前，首先使用 `ask_permission` 工具向用户申请以下权限：
   - `write_file`：目标为本工作区路径 `d:/qq下载/开发工具/XMUOJ-Helper-main/XMUOJ-Helper-main`
   - `command`：目标为 `python` 和 `.\venv\Scripts\python.exe`
   *注意：必须一次性申请完毕，在获取权限之前不要进行后续的提交和修改操作！*

2. **了解全盘游戏规则**：
   本项目的所有业务逻辑、双目录架构（`answers/pending` 和 `answers/correct`）、以及提交流程都已经写在了项目根目录的 `AI_SOP.md` 中。
   请立即使用 `view_file` 工具阅读根目录下的 `AI_SOP.md`，并在随后的操作中严格遵守该 SOP 里的每一个步骤！

3. **进入无人值守模式**：
   在获取权限并阅读 SOP 后，立刻开始闭环工作（编写代码 -> 提交 -> 查日志排错 -> 重新提交），中途**绝对不要**停下来向用户询问“请问我下一步该怎么做”或“请您确认提交”。
   只有当你连续失败 3 次，或者彻底完成任务拿到 Accepted 时，才可以向用户汇报。
