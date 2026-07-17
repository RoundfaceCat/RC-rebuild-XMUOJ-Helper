#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int k = min(n, m);
    int N = n + m;
    long long ans = 1;
    for (int i = 1; i <= k; ++i) {
        ans = ans * (N - k + i) / i;
    }
    cout << ans << endl;
    return 0;
}