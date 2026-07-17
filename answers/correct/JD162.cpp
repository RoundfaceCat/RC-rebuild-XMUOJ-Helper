#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> grid;
vector<vector<int>> dp;

int dfs(int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];
    dp[i][j] = 1;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if (ni >= 0 && ni < R && nj >= 0 && nj < C && grid[ni][nj] < grid[i][j]) {
            dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj));
        }
    }
    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    grid.assign(R, vector<int>(C));
    dp.assign(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> grid[i][j];

    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            ans = max(ans, dfs(i, j));

    cout << ans << "\n";
    return 0;
}
