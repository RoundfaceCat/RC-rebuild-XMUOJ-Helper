#include <iostream>
#include <algorithm>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    int maxVal = std::max({A, B, C});
    std::cout << "Max = " << maxVal << std::endl;
    return 0;
}