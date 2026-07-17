#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if (B > A) {
        cout << B - A << endl;
    } else if (B == A) {
        cout << 24 << endl;
    } else {
        cout << 24 - A + B << endl;
    }
    return 0;
}