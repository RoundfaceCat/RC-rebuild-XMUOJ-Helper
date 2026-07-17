// JD136: 剑谱寻踪 - KMP String Matching
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        string pattern;
        cin >> pattern;
        int m;
        cin >> m;
        string text;
        cin >> text;

        // Build KMP failure function (prefix function)
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && pattern[i] != pattern[j])
                j = pi[j - 1];
            if (pattern[i] == pattern[j]) j++;
            pi[i] = j;
        }

        // KMP matching
        vector<int> results;
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j > 0 && text[i] != pattern[j])
                j = pi[j - 1];
            if (text[i] == pattern[j]) j++;
            if (j == n) {
                results.push_back(i - n + 1);
                j = pi[j - 1];
            }
        }

        // Output
        for (int i = 0; i < (int)results.size(); i++) {
            if (i > 0) cout << ' ';
            cout << results[i];
        }
        cout << '\n';
    }

    return 0;
}
