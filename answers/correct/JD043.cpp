#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] <= 0) a[i] = 1;
    }
    for (int i = 0; i < N; ++i) {
        cout << "X[" << i << "] = " << a[i] << "\n";
    }
    return 0;
}