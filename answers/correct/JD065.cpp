#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << (1 << (i + j));
                if (i == N - 1 && j == N - 1) {
                    // 最后一个数字不加空格
                } else {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
        cout << '\n'; // 每个矩阵后跟一个空行
    }
    return 0;
}