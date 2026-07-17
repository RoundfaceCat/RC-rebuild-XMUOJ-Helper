// 本解法与“背包叠甲”完全相同，只是数据更大，但数组已开到足够大
// 为了体现区别，这里直接复用代码，但可调整数组大小
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXV 20005
#define MAXN 1005

int dp[MAXV];
int w[MAXN * 15], v[MAXN * 15], cnt;

int main() {
    int N, V;
    scanf("%d%d", &N, &V);
    cnt = 0;
    for (int i = 0; i < N; i++) {
        int vi, wi, s;
        scanf("%d%d%d", &vi, &wi, &s);
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