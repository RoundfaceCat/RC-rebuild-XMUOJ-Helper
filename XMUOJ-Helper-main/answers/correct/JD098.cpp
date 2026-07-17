#include <iostream>
#include <vector>

int main() {
    std::vector<int> vals;
    int x;
    while (std::cin >> x) {
        if (x == -1) break;
        vals.push_back(x);
    }
    // 从尾到头输出，每行一个
    for (auto it = vals.rbegin(); it != vals.rend(); ++it) {
        std::cout << *it << '\n';
    }
    return 0;
}