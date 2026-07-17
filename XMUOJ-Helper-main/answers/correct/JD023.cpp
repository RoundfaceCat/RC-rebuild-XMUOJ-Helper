#include <iostream>
#include <iomanip>

int main() {
    double salary;
    std::cin >> salary;

    int p;
    if (salary <= 400.0) {
        p = 15;
    } else if (salary <= 800.0) {
        p = 12;
    } else if (salary <= 1200.0) {
        p = 10;
    } else if (salary <= 2000.0) {
        p = 7;
    } else {
        p = 4;
    }

    double increase = salary * p / 100.0;
    double new_salary = salary + increase;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "New salary: " << new_salary << "\n";
    std::cout << "Increase: " << increase << "\n";
    std::cout << "Percentage: " << p << " %" << std::endl;

    return 0;
}