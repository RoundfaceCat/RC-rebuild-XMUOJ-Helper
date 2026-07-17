#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << setw(3) << abs(i - j) + 1;
            }
            cout << "\n";
        }
        cout << "\n"; // 每个矩阵后跟一个空行
    }
    return 0;
}