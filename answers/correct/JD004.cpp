#include <iostream>
#include <iomanip>

int main() {
    int id, quantity;
    double price;
    std::cin >> id >> quantity >> price;
    double total = quantity * price;
    std::cout << "TOTAL = " << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}