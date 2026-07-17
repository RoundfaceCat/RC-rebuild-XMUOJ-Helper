#include <iostream>
#include <vector>
#include <cstdio>

void solve() {
    char tp;
    std::cin >> tp;
    std::vector<std::vector<double>> a(12, std::vector<double>(12));
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            std::cin >> a[i][j];
    double sum = 0.0;
    int cnt = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (i > j && i + j > 11) {
                sum += a[i][j];
                ++cnt;
            }
        }
    }
    if (tp == 'S')
        printf("%.1lf\n", sum);
    else
        printf("%.1lf\n", sum / cnt);
}

int main() {
    int T = 1;
    while (T--) solve();
    return 0;
}