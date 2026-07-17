#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    char op;
    std::cin >> op;
    
    const int n = 12;
    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> a[i][j];
    
    double sum = 0.0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j < i && i + j < 11) {
                sum += a[i][j];
                ++cnt;
            }
        }
    }
    
    double ans = (op == 'S') ? sum : sum / cnt;
    std::cout << std::fixed << std::setprecision(1) << ans << std::endl;
    return 0;
}