#include <iostream>

int main() {
    int cnt = 0;
    for (int i = 0; i < 6; ++i) {
        double x;
        std::cin >> x;
        if (x > 0) ++cnt;
    }
    std::cout << cnt << " positive numbers" << std::endl;
    return 0;
}