#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int mask = 1; mask < (1 << n); ++mask) {
        bool first = true;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                if (!first) cout << ' ';
                cout << i + 1;
                first = false;
            }
        }
        cout << '\n';
    }
    return 0;
}