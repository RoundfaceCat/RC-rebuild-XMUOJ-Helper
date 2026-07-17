#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        // Ensure n <= m to minimize state space
        if (n > m) swap(n, m);

        // If total cells are odd, no tiling exists
        if ((n * m) % 2 != 0) {
            cout << 0 << '\n';
            continue;
        }

        // DP: dp[mask] = ways to fill processed columns with given protrusion mask
        vector<long long> dp(1 << n, 0);
        dp[0] = 1;

        // Process column by column
        for (int col = 0; col < m; ++col) {
            vector<long long> next_dp(1 << n, 0);
            for (int mask = 0; mask < (1 << n); ++mask) {
                if (dp[mask] == 0) continue;

                // Recursively fill the current column given the incoming mask
                function<void(int, int, int)> dfs = [&](int row, int cur, int nxt) {
                    if (row == n) {
                        next_dp[nxt] += dp[mask];
                        return;
                    }
                    // Already occupied by a horizontal domino from previous column
                    if (cur & (1 << row)) {
                        dfs(row + 1, cur, nxt);
                    } else {
                        // Option 1: place a horizontal domino starting here
                        // It fills this cell and sets the same row in the next mask
                        dfs(row + 1, cur | (1 << row), nxt | (1 << row));

                        // Option 2: place a vertical domino (if possible)
                        if (row + 1 < n && !(cur & (1 << (row + 1)))) {
                            // Fill both current and next row in the current column
                            dfs(row + 2, cur | (1 << row) | (1 << (row + 1)), nxt);
                        }
                    }
                };

                dfs(0, mask, 0);
            }
            dp = move(next_dp);
        }

        // After filling all m columns, the mask must be 0 (no overhang)
        cout << dp[0] << '\n';
    }

    return 0;
}