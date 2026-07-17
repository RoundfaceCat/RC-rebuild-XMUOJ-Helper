#include <iostream>
#include <string>

int main() {
    std::string a;
    std::getline(std::cin, a);          // 读取整行，可能包含空格
    std::string b;
    int n = static_cast<int>(a.size());
    b.reserve(n);
    for (int i = 0; i < n; ++i) {
        int sum = static_cast<int>(a[i]) + static_cast<int>(a[(i + 1) % n]);
        b.push_back(static_cast<char>(sum));
    }
    std::cout << b << std::endl;
    return 0;
}