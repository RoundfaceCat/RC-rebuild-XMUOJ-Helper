#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double r;
    std::cin >> r;
    const double pi = 3.14159;
    double volume = (4.0 / 3.0) * pi * std::pow(r, 3);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "VOLUME = " << volume << std::endl;
    return 0;
}