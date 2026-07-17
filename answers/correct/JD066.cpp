#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // 向右
        for (int i = left; i <= right; ++i) {
            a[top][i] = num++;
        }
        ++top;
        // 向下
        for (int i = top; i <= bottom; ++i) {
            a[i][right] = num++;
        }
        --right;
        // 向左
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                a[bottom][i] = num++;
            }
            --bottom;
        }
        // 向上
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                a[i][left] = num++;
            }
            ++left;
        }
    }

    // 输出矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    // 输出一个空行
    cout << "\n";

    return 0;
}