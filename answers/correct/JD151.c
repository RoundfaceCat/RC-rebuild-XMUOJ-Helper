#include <stdio.h>
#include <string.h>

#define MAXN 205
#define INF 0x3f3f3f3f

int dp[MAXN][MAXN];

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        if (w < dp[a][b]) dp[a][b] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (dp[k][j] == INF) continue;
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (dp[a][b] == INF) printf("impossible\n");
        else printf("%d\n", dp[a][b]);
    }
    return 0;
}