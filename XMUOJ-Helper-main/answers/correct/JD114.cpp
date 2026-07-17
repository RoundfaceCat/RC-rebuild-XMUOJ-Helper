#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;  // 根据样例，第一行实为 n m x

    vector<int> A(n);
    for (int i = 0; i < n; ++i) 
        cin >> A[i];

    vector<int> B(m);
    for (int i = 0; i < m; ++i)
        cin >> B[i];

    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
        int s = A[i] + B[j];
        if (s == x) {
            cout << i << ' ' << j << '\n';  // 0‑based 下标
            break;
        } else if (s < x) {
            ++i;
        } else {
            --j;
        }
    }

    return 0;
}