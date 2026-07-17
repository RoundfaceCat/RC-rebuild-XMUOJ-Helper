#include <iostream>
#include <iomanip>

int main() {
    int x, y;
    std::cin >> x >> y;
    double price[] = {0.0, 4.00, 4.50, 5.00, 2.00, 1.50};
    double total = price[x] * y;
    std::cout << "Total: R$ " << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}