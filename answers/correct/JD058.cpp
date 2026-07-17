#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char op;
    while (cin >> op) {
        double a[12][12];
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j < 12; ++j)
                cin >> a[i][j];

        double sum = 0.0;
        int cnt = 0;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 12; ++j) {
                if (j > i && i + j > 11) {
                    sum += a[i][j];
                    ++cnt;
                }
            }
        }

        double ans = (op == 'S') ? sum : sum / cnt;
        printf("%.1f\n", ans);
    }
    return 0;
}