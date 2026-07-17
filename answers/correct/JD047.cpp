#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> data;
    int x;
    while (std::cin >> x) {
        data.push_back(x);
    }

    if (data.empty()) return 0;
    int n = data[0];
    if (n <= 0) return 0;  // 无效或空数组不输出

    int count = std::min(n, static_cast<int>(data.size()) - 1);
    if (count == 0) return 0;

    int min_val = data[1];
    int min_pos = 0;
    for (int i = 1; i < count; ++i) {
        if (data[1 + i] < min_val) {
            min_val = data[1 + i];
            min_pos = i;
        }
    }

    std::cout << "Menor valor: " << min_val << "\n";
    std::cout << "Posicao: " << min_pos << "\n";
    return 0;
}