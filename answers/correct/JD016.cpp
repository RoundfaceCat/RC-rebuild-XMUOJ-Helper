#include <iostream>
#include <iomanip>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;

    bool is_triangle = (A + B > C) && (A + C > B) && (B + C > A);

    std::cout << std::fixed << std::setprecision(1);
    if (is_triangle) {
        double perimeter = A + B + C;
        std::cout << "Perimeter = " << perimeter << std::endl;
    } else {
        double area = (A + B) * C / 2.0;
        std::cout << "Area = " << area << std::endl;
    }

    return 0;
}