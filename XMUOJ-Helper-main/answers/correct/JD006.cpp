#include <iostream>
#include <iomanip>

int main() {
    double A, B;
    std::cin >> A >> B;
    double average = (A * 3.5 + B * 7.5) / 11.0;
    std::cout << "Average = " << std::fixed << std::setprecision(5) << average << std::endl;
    return 0;
}