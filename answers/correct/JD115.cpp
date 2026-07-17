#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    
    int i = 0;
    for (int j = 0; j < m && i < n; ++j) {
        if (a[i] == b[j]) {
            ++i;
        }
    }
    
    cout << (i == n ? "Yes" : "No") << '\n';
    return 0;
}