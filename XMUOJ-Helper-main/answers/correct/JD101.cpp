#include <iostream>
#include <vector>

int main() {
    std::vector<int> a, b;
    int x;
    while (std::cin >> x && x != -1) a.push_back(x);
    while (std::cin >> x && x != -1) b.push_back(x);

    std::vector<int> res;
    std::size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);

    for (std::size_t k = 0; k < res.size(); ++k) {
        if (k) std::cout << ' ';
        std::cout << res[k];
    }
    std::cout << std::endl;
    return 0;
}