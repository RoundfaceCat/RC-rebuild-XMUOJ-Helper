#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (char c : s) {
        if (cnt[c - 'a'] == 1) {
            std::cout << c;
            return 0;
        }
    }

    std::cout << "no";
    return 0;
}