#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << " x " << n << " = " << i * n << '\n';
    }
    return 0;
}