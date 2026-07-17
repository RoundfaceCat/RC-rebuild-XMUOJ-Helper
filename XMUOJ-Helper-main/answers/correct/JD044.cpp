#include <iostream>
using namespace std;

int main() {
    long long V;
    cin >> V;
    cout << "N[0] = " << V << endl;
    for (int i = 1; i < 10; ++i) {
        V *= 2;
        cout << "N[" << i << "] = " << V << endl;
    }
    return 0;
}