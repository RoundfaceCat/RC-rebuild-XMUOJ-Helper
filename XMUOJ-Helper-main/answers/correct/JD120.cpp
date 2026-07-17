#include <iostream>
#include <vector>
using namespace std;

vector<int> fa, d;

int find(int x) {
    if (fa[x] != x) {
        int t = fa[x];
        fa[x] = find(fa[x]);
        d[x] = (d[x] + d[t]) % 3;
    }
    return fa[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    fa.resize(n + 1);
    d.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) fa[i] = i;

    int ans = 0;
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n) {
            ++ans;
            continue;
        }
        if (op == 2 && x == y) {
            ++ans;
            continue;
        }
        int rx = find(x), ry = find(y);
        if (rx == ry) {
            // 检查冲突
            int delta = (d[x] - d[y] + 3) % 3;
            if (op == 1 && delta != 0) ++ans;
            if (op == 2 && delta != 1) ++ans;
        } else {
            // 合并
            fa[rx] = ry;
            if (op == 1) {
                // 同类：d[x] + d[rx] ≡ d[y] (mod 3)
                d[rx] = (d[y] - d[x] + 3) % 3;
            } else {
                // x 吃 y：d[x] + d[rx] ≡ d[y] + 1 (mod 3)
                d[rx] = (d[y] + 1 - d[x] + 3) % 3;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}