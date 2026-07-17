#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> last_pos;
    int left = 0, ans = 0;
    for (int right = 0; right < n; ++right) {
        auto it = last_pos.find(a[right]);
        if (it != last_pos.end() && it->second >= left) {
            left = it->second + 1;
        }
        last_pos[a[right]] = right;
        ans = max(ans, right - left + 1);
    }
    cout << ans << "\n";
    return 0;
}