#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        int x;
        cin >> x;
        auto left = lower_bound(a.begin(), a.end(), x);
        if (left == a.end() || *left != x) {
            cout << "-1 -1\n";
        } else {
            auto right = upper_bound(a.begin(), a.end(), x);
            cout << (left - a.begin()) << ' ' << (right - a.begin() - 1) << '\n';
        }
    }

    return 0;
}