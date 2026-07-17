#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int max_val = a[0];
    int pos = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > max_val) {
            max_val = a[i];
            pos = i + 1;
        }
    }
    
    std::cout << max_val << '\n' << pos << '\n';
    return 0;
}