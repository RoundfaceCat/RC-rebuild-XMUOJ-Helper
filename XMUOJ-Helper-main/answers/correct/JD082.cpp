#include <iostream>
#include <algorithm>

// 实现题目要求的函数
int maxOfTwo(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << maxOfTwo(x, y);
    return 0;
}