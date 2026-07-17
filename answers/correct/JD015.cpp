#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if ((B != 0 && A % B == 0) || (A != 0 && B % A == 0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}