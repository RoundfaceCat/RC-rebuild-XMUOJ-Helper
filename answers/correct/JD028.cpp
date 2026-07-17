#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    double income;
    cin >> income;

    cout << fixed << setprecision(2);

    if (income <= 2000.00) {
        cout << "Isento" << endl;
    } else {
        double tax = 0.0;

        // 第二档：2000.01 ~ 3000.00 部分 8%
        double part2 = min(max(0.0, income - 2000.0), 1000.0);
        tax += part2 * 0.08;

        // 第三档：3000.01 ~ 4500.00 部分 18%
        double part3 = min(max(0.0, income - 3000.0), 1500.0);
        tax += part3 * 0.18;

        // 第四档：4500.01 以上部分 28%
        double part4 = max(0.0, income - 4500.0);
        tax += part4 * 0.28;

        cout << "R$ " << tax << endl;
    }

    return 0;
}