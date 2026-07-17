#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char op;
    cin >> op;
    double sum = 0.0;
    int cnt = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            double x;
            cin >> x;
            if (i < j && i + j < 11) {   // 左上三角区域
                sum += x;
                ++cnt;
            }
        }
    }
    cout << fixed << setprecision(1);
    if (op == 'S')
        cout << sum << '\n';
    else
        cout << sum / cnt << '\n';
    return 0;
}