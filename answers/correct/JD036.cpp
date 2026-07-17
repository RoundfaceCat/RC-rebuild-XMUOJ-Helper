#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    long long L = a + 1;
    long long R = b - 1;
    long long sum = 0;
    if (L <= R) {
        long long s = L;
        if (!(s & 1)) s++;
        long long e = R;
        if (!(e & 1)) e--;
        if (s <= e) {
            long long cnt = (e - s) / 2 + 1;
            sum = cnt * (s + e) / 2;
        }
    }
    cout << sum << endl;
    return 0;
}