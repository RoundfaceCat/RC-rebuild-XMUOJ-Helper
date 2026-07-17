#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findAll(const string& text, const string& pattern) {
    vector<int> matches;
    int n = text.size(), m = pattern.size();
    if (m == 0) return matches;
    vector<int> pi(m);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        pi[i] = j;
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j])
            ++j;
        if (j == m) {
            matches.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return matches;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    // 分割三个字符串
    size_t p1 = line.find(',');
    size_t p2 = line.find(',', p1 + 1);
    string S = line.substr(0, p1);
    string S1 = line.substr(p1 + 1, p2 - p1 - 1);
    string S2 = line.substr(p2 + 1);

    vector<int> pos1 = findAll(S, S1);
    vector<int> pos2 = findAll(S, S2);
    if (pos1.empty() || pos2.empty()) {
        cout << -1;
        return 0;
    }

    int min_end = *min_element(pos1.begin(), pos1.end()) + (int)S1.size();
    int max_start = *max_element(pos2.begin(), pos2.end());

    if (min_end <= max_start)
        cout << max_start - min_end;
    else
        cout << -1;

    return 0;
}