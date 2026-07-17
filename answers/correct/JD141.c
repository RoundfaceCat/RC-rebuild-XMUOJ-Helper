#include <stdio.h>
int a[10], used[10], n;
void dfs(int d) {
    if (d == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        putchar(10);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = 1;
            a[d] = i;
            dfs(d + 1);
            used[i] = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}