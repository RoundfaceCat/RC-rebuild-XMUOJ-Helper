#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, sz;
    cin >> n >> m >> sz;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    int limit = min({sz, n, m});
    for (int i = 0; i < limit; ++i) b[i] = a[i];
    for (int i = 0; i < m; ++i) {
        if (i > 0) cout << ' ';
        cout << b[i];
    }
    cout << '\n';
    return 0;
}