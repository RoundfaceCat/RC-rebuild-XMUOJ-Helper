#include <iostream>
#include <iomanip>

int main() {
    double r;
    std::cin >> r;
    constexpr double PI = 3.14159;
    double area = PI * r * r;
    std::cout << "A=" << std::fixed << std::setprecision(4) << area << std::endl;
    return 0;
}