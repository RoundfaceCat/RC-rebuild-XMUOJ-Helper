#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MAX = 60;
    vector<long long> fib(MAX + 1);
    fib[0] = 0;
    if (MAX >= 1) fib[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << fib[i];
        }
        cout << "\n";
    }
    return 0;
}