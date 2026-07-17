#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    
    // in case the given lengths don't match the actual strings (safety)
    if (static_cast<int>(a.size()) != n) a.resize(n);
    if (static_cast<int>(b.size()) != m) b.resize(m);
    
    // space-optimized DP: two rows of length m+1
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cur[0] = 0;
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                cur[j] = prev[j - 1] + 1;
            } else {
                cur[j] = max(prev[j], cur[j - 1]);
            }
        }
        swap(prev, cur);
    }
    
    cout << prev[m] << '\n';
    return 0;
}