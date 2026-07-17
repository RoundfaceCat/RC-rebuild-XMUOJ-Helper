#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

// 给以 (x1, y1) 为左上角，(x2, y2) 为右下角的矩形整体加 c
void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    cin >> n >> m >> q;

    // 读入原矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // 初始化差分矩阵
    // 等价于把每个原始元素 a[i][j] 单独插入到 (i,j)-(i,j)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            insert(i, j, i, j, a[i][j]);
        }
    }

    // 执行 q 次矩形加法操作
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    // 对差分矩阵求二维前缀和，得到最终矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}