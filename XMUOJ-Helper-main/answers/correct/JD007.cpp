#include <iostream>
#include <iomanip>

int main() {
    int number;
    int days;
    double rate;
    std::cin >> number;
    std::cin >> days >> rate;
    double salary = days * rate;
    std::cout << "NUMBER = " << number << std::endl;
    std::cout << "SALARY = U$ " << std::fixed << std::setprecision(2) << salary << std::endl;
    return 0;
}