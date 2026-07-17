#include <bits/stdc++.h>
using namespace std;

// Check if edit distance between a and b is <= k
bool edit_distance_le(const string& a, const string& b, int k) {
    int n = (int)a.size(), m = (int)b.size();
    // If length diff exceeds k, edit distance cannot be <= k
    if (abs(n - m) > k) return false;
    // Ensure a is the shorter string to reduce DP row size
    if (n > m) return edit_distance_le(b, a, k);
    // dp is the previous row, ndp is the current row
    vector<int> dp(m + 1), ndp(m + 1);
    iota(dp.begin(), dp.end(), 0); // dp[j] = j

    for (int i = 1; i <= n; ++i) {
        ndp[0] = i; // delete all from shorter string
        for (int j = 1; j <= m; ++j) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            ndp[j] = min({dp[j] + 1, ndp[j - 1] + 1, dp[j - 1] + cost});
        }
        // Early exit: if minimum in this row > k, no need to continue
        bool possible = false;
        for (int j = 0; j <= m; ++j) {
            if (ndp[j] <= k) { possible = true; break; }
        }
        if (!possible) return false;
        swap(dp, ndp);
    }
    return dp[m] <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> dict(N);
    for (int i = 0; i < N; ++i) {
        cin >> dict[i];
    }

    while (M--) {
        string s;
        int k;
        cin >> s >> k;
        int cnt = 0;
        for (const auto& w : dict) {
            if (edit_distance_le(w, s, k)) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}