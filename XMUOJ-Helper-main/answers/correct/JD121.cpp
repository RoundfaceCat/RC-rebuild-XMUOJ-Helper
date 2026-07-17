#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main() {
    cin >> n >> m;

    // 读入原数组，使用 1 下标
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 计算前缀和
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    // 回答 m 次查询
    while (m--) {
        int l, r;
        cin >> l >> r;

        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}