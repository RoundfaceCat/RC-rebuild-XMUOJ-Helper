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
    double sum = 0.0;
    int cnt = 0;
    for (int i = 0; i < 12; ++i)
        for (int j = i + 1; j < 12; ++j) {
            sum += a[i][j];
            ++cnt;
        }
    if (op == 'M') sum /= cnt;
    cout << fixed << setprecision(1) << sum << endl;
    return 0;
}