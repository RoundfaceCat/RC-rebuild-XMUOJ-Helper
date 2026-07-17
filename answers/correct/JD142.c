#include <stdio.h>
int n, first = 1;
int col[20], d1[40], d2[40];
char b[20][21];
void dfs(int r) {
    if (r == n) {
        if (!first) putchar(10);
        first = 0;
        for (int i = 0; i < n; i++)
            puts(b[i]);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !d1[r+c] && !d2[r-c+20]) {
            col[c] = d1[r+c] = d2[r-c+20] = 1;
            b[r][c] = 'Q';
            dfs(r + 1);
            b[r][c] = '.';
            col[c] = d1[r+c] = d2[r-c+20] = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            b[i][j] = '.';
        b[i][n] = 0;
    }
    dfs(0);
    return 0;
}