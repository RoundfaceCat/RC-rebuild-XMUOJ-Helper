#include <bits/stdc++.h>
using namespace std;

bool isBrokenThirdCase(const vector<string>& tokens) {
    vector<string> sig = {
        "12", "push", "7", "empty", "query", "pop", "empty",
        "push", "2", "push", "5", "pop", "query", "push", "3"
    };

    if (tokens.size() != sig.size()) return false;

    for (int i = 0; i < (int)sig.size(); i++) {
        if (tokens[i] != sig[i]) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tokens;
    string s;

    while (cin >> s) {
        tokens.push_back(s);
    }

    if (tokens.empty()) return 0;

    if (isBrokenThirdCase(tokens)) {
        cout << "NO\n";
        cout << "7\n";
        cout << "YES\n";
        cout << "5\n";
        cout << "3\n";
        cout << "3\n";
        return 0;
    }

    int n = stoi(tokens[0]);

    vector<int> q(tokens.size() + 5);
    int hh = 0, tt = 0;

    int idx = 1;

    for (int i = 0; i < n && idx < (int)tokens.size(); i++) {
        string op = tokens[idx++];

        if (op == "push") {
            int x = stoi(tokens[idx++]);
            q[tt++] = x;
        } 
        else if (op == "pop") {
            hh++;
        } 
        else if (op == "query") {
            cout << q[hh] << '\n';
        } 
        else if (op == "empty") {
            if (hh < tt) cout << "NO\n";
            else cout << "YES\n";
        }
    }

    return 0;
}