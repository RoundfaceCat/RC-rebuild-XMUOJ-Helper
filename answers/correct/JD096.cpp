#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string ans;
    for (char c : s) {
        if (c == ' ') {
            ans += "%20";
        } else {
            ans.push_back(c);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}