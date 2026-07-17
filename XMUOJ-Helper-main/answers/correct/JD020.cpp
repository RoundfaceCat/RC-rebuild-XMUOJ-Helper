#include <iostream>

int main() {
    double x;
    std::cin >> x;
    if (x >= 0.0 && x <= 25.0) {
        std::cout << "Interval [0,25]" << std::endl;
    } else if (x > 25.0 && x <= 50.0) {
        std::cout << "Interval (25,50]" << std::endl;
    } else if (x > 50.0 && x <= 75.0) {
        std::cout << "Interval (50,75]" << std::endl;
    } else if (x > 75.0 && x <= 100.0) {
        std::cout << "Interval (75,100]" << std::endl;
    } else {
        std::cout << "Out of interval" << std::endl;
    }
    return 0;
}