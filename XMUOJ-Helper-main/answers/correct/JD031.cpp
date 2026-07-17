#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    while (cin >> x && x != 0) {
        if (x > 0) {
            for (int i = 1; i <= x; ++i) {
                if (i > 1) cout << ' ';
                cout << i;
            }
            cout << '\n';
        }
    }
    return 0;
}