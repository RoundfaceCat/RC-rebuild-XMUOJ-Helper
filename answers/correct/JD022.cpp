#include <iostream>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    int start = A * 60 + B;
    int end = C * 60 + D;
    int diff = end - start;
    if (diff <= 0) {
        diff += 24 * 60;
    }
    int hours = diff / 60;
    int minutes = diff % 60;
    std::cout << hours << ":" << minutes;
    return 0;
}