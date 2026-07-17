#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> values;
    int x;
    while (std::cin >> x && x != -1) {
        values.push_back(x);
    }
    std::reverse(values.begin(), values.end());
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << values[i];
    }
    std::cout << '\n';
    return 0;
}