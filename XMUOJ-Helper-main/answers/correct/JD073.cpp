#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    for (char& c : s) {
        if ('a' <= c && c <= 'z') {
            c = (c - 'a' + 1) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            c = (c - 'A' + 1) % 26 + 'A';
        }
        // 数字和其他字符原样输出
    }

    std::cout << s << std::endl;
    return 0;
}