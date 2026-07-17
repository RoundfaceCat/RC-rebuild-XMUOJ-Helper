#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> path;
vector<bool> used;

void dfs(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ' ';
            cout << path[i];
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            path.push_back(i);
            dfs(depth + 1);
            path.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    used.assign(n + 1, false);
    path.reserve(n);
    dfs(0);
    return 0;
}