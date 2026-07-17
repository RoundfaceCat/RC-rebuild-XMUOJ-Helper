#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXV 20005
#define MAXN 1005

int dp[MAXV];
int w[MAXN * 15], v[MAXN * 15], cnt; // 拆分后的物品

int main() {
    int N, V;
    scanf("%d%d", &N, &V);
    cnt = 0;
    for (int i = 0; i < N; i++) {
        int vi, wi, s;
        scanf("%d%d%d", &vi, &wi, &s);
        // 二进制拆分
        int k = 1;
        while (k <= s) {
            w[++cnt] = wi * k;
            v[cnt] = vi * k;
            s -= k;
            k <<= 1;
        }
        if (s > 0) {
            w[++cnt] = wi * s;
            v[cnt] = vi * s;
        }
    }
    // 01背包
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= cnt; i++) {
        for (int j = V; j >= v[i]; j--) {
            if (dp[j - v[i]] + w[i] > dp[j])
                dp[j] = dp[j - v[i]] + w[i];
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}