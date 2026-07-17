#include <stdio.h>
int n, m;
int a[105][105];
int qx[10005], qy[10005];
int dist[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    if (a[0][0] == 1 || a[n-1][m-1] == 1) {
        printf("-1\n");
        return 0;
    }

    int head = 0, tail = 0;
    qx[tail] = 0; qy[tail] = 0; tail++;
    a[0][0] = 1;

    while (head < tail) {
        int x = qx[head], y = qy[head]; head++;
        if (x == n-1 && y == m-1) {
            printf("%d\n", dist[x][y]);
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 0) {
                a[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                qx[tail] = nx; qy[tail] = ny; tail++;
            }
        }
    }

    printf("-1\n");
    return 0;
}