#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100010;
vector<int> adj[N];
int color[N];

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = color[u] == 1 ? 2 : 1;
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && !bfs(i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}