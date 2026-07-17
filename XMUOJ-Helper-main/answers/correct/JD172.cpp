#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> happy(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> happy[i];
    }

    vector<vector<int>> adj(N + 1);
    vector<int> indeg(N + 1, 0);
    // 读入 N-1 条边，但为了应对可能的不连通（森林），我们直接读到 EOF
    // 但由于题目保证是树或森林，我们根据给定的边数读取
    // 原题应为 N-1 条边，这里用 for 循环 N-1 次
    for (int i = 0; i < N - 1; ++i) {
        int l, k;
        cin >> l >> k;  // l 的上司是 k
        adj[k].push_back(l);
        indeg[l]++;
    }

    // dp[u][0]: u 不出征; dp[u][1]: u 出征
    vector<array<long long, 2>> dp(N + 1);

    // DFS 计算 dp
    function<void(int)> dfs = [&](int u) {
        dp[u][0] = 0;
        dp[u][1] = happy[u];
        for (int v : adj[u]) {
            dfs(v);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };

    long long ans = 0;
    // 可能有多个入度为 0 的节点（森林）
    for (int i = 1; i <= N; ++i) {
        if (indeg[i] == 0) {
            dfs(i);
            ans += max(dp[i][0], dp[i][1]);
        }
    }

    cout << ans << "\n";
    return 0;
}