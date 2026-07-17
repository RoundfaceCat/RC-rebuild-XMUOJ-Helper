#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char op;
    cin >> op;
    double a[12][12];
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            cin >> a[i][j];
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            if (i + j < 11) {
                sum += a[i][j];
                ++cnt;
            }
    cout << fixed << setprecision(1);
    if (op == 'S')
        cout << sum;
    else // 'M'
        cout << sum / cnt;
    return 0;
}