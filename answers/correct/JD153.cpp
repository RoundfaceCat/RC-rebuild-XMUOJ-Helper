#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, M = 200010;
int n, m;
int p[N];

struct Edge {
    int a, b, w;
    bool operator<(const Edge& t) const {
        return w < t.w;
    }
} e[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b, w};
    }
    sort(e, e + m);
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = e[i].a, b = e[i].b, w = e[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}