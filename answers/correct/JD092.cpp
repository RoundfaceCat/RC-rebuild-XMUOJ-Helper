#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a = 1, b = 1;  // f(1) = 1, f(2) = 1
    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 3; i <= n; ++i) {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << b << endl;
    return 0;
}