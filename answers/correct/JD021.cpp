#include <iostream>
#include <cmath>

int main() {
    double x, y;
    std::cin >> x >> y;

    const double eps = 1e-9;

    bool zeroX = std::fabs(x) < eps;
    bool zeroY = std::fabs(y) < eps;

    if (zeroX && zeroY) {
        std::cout << "Origem" << std::endl;
    } else if (zeroX) {
        std::cout << "Eixo Y" << std::endl;
    } else if (zeroY) {
        std::cout << "Eixo X" << std::endl;
    } else if (x > 0 && y > 0) {
        std::cout << "Q1" << std::endl;
    } else if (x < 0 && y > 0) {
        std::cout << "Q2" << std::endl;
    } else if (x < 0 && y < 0) {
        std::cout << "Q3" << std::endl;
    } else {
        std::cout << "Q4" << std::endl;
    }

    return 0;
}