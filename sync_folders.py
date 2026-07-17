import os
import shutil
import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
from xmuoj_bot import XMUOJBot
import json

def sync_folders():
    with open('config.json', 'r') as f:
        config = json.load(f)
    bot = XMUOJBot(config['username'], config['password'], config['base_url'])
    if not bot.login():
        print("Login failed")
        return
        
    problems = bot.get_contest_problems(361)
    if not problems:
        print("Could not fetch contest problems")
        return
        
    pending_dir = os.path.join('answers', 'pending')
    correct_dir = os.path.join('answers', 'correct')
    os.makedirs(pending_dir, exist_ok=True)
    os.makedirs(correct_dir, exist_ok=True)
    
    moved = 0
    for p in problems:
        if p['my_status'] == 0:  # Accepted
            # Check if it's in pending
            pending_file = os.path.join(pending_dir, f"{p['display_id']}.py")
            if not os.path.exists(pending_file):
                pending_file = os.path.join(pending_dir, f"{p['display_id']}.txt")
                
            if os.path.exists(pending_file):
                correct_file = os.path.join(correct_dir, os.path.basename(pending_file))
                if os.path.exists(correct_file):
                    os.remove(correct_file)
                shutil.move(pending_file, correct_file)
                print(f"[+] Synced {p['display_id']} to correct/")
                moved += 1
                
    print(f"Sync complete. Moved {moved} files.")

if __name__ == "__main__":
    sync_folders()
