#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int stk[N], tt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            stk[++tt] = x;
        } else if (op == "pop") {
            if (tt > 0) --tt;
        } else if (op == "empty") {
            cout << (tt ? "NO" : "YES") << '\n';
        } else { // query
            cout << stk[tt] << '\n';
        }
    }
    return 0;
}