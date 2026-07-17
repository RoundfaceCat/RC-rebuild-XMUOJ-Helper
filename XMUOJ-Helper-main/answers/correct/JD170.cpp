#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> dist(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    // dp[mask][i] = minimum cost to visit the set of cities `mask`, ending at city i
    // 1<<n states, start with city 0 only
    const long long INF = 1e18;
    vector<vector<long long>> dp(1 << n, vector<long long>(n, INF));
    dp[1][0] = 0; // mask = 1 means only city 0 visited

    for (int mask = 1; mask < (1 << n); ++mask) {
        // require that city 0 is always visited (optional pruning)
        if (!(mask & 1)) continue;

        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue; // i is not in current set
            if (dp[mask][i] == INF) continue;

            // try to go to an unvisited city j
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue; // already visited
                int nxtMask = mask | (1 << j);
                dp[nxtMask][j] = min(dp[nxtMask][j], dp[mask][i] + dist[i][j]);
            }
        }
    }

    // The answer is the minimum cost to visit all cities and end at n-1
    long long ans = dp[(1 << n) - 1][n - 1];
    cout << ans << '\n';

    return 0;
}