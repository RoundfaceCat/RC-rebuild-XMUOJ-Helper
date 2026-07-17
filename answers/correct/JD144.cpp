#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int bfs(string start) {
    // 目标状态固定为 1 2 3 4 5 6 7 8 x
    string target = "12345678x";

    if (start == target) return 0;

    int dx[4] = {-3, 3, -1, 1};
    queue<string> q;
    unordered_map<string, int> dist;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        string t = q.front();
        q.pop();
        
        int distance = dist[t];
        int pos = t.find('x');

        for (int i = 0; i < 4; i++) {
            int new_pos = pos + dx[i];
            
            if (new_pos >= 0 && new_pos < 9) {
                // 检查边界：左移右移不能跨行
                if (i < 2 || (pos / 3 == new_pos / 3)) {
                    string next = t;
                    swap(next[pos], next[new_pos]);

                    if (next == target) return distance + 1;

                    if (dist.find(next) == dist.end()) {
                        dist[next] = distance + 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    string start, c;
    // 核心逻辑：一直读取字符直到读完 9 个
    for (int i = 0; i < 9; i++) {
        cin >> c;
        start += c;
    }
    
    cout << bfs(start) << endl;
    return 0;
}