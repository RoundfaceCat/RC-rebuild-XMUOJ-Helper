#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> seg(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        seg[i] = {a, b};
    }

    sort(seg.begin(), seg.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.second < y.second;
    });

    int ans = 0;
    int last = -0x3f3f3f3f;

    for (auto& p : seg) {
        int l = p.first;
        int r = p.second;

        if (l > last) {
            ans++;
            last = r;
        }
    }

    cout << ans << '\n';

    return 0;
}