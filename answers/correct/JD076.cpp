#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, sub;
    while (cin >> s >> sub) {
        if (s.empty()) {
            cout << sub << "\n";
            continue;
        }
        int pos = 0;
        char maxc = s[0];
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] > maxc) {
                maxc = s[i];
                pos = i;
            }
        }
        string ans = s.substr(0, pos + 1) + sub + s.substr(pos + 1);
        cout << ans << "\n";
    }
    return 0;
}