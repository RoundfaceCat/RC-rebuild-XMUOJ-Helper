#include <stdio.h>
#include <string.h>

#define MAXV 1005
#define MAXN 105

int dp[MAXV];
int v[MAXN], w[MAXN];

int main() {
    int N, V;
    scanf("%d%d", &N, &V);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
        int S;
        scanf("%d", &S);
        for (int j = 0; j < S; j++) {
            scanf("%d%d", &v[j], &w[j]);
        }
        // 逆序容量
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k < S; k++) {
                if (j >= v[k]) {
                    if (dp[j - v[k]] + w[k] > dp[j])
                        dp[j] = dp[j - v[k]] + w[k];
                }
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}