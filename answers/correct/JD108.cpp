#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double n;
    std::cin >> n;
    
    double left = -10000.0, right = 10000.0;
    while (right - left > 1e-8) {
        double mid = (left + right) / 2.0;
        if (mid * mid * mid >= n) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    std::cout << std::fixed << std::setprecision(6) << left << std::endl;
    return 0;
}