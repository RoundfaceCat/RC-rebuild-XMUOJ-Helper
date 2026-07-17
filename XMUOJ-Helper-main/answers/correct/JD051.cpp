#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    int L;
    char op;
    std::cin >> L >> op;
    
    std::vector<std::vector<double>> grid(12, std::vector<double>(12));
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            std::cin >> grid[i][j];
    
    double sum = 0.0;
    for (int j = 0; j < 12; ++j)
        sum += grid[L][j];
    
    double ans = (op == 'S') ? sum : sum / 12.0;
    std::cout << std::fixed << std::setprecision(1) << ans << "\n";
    
    return 0;
}