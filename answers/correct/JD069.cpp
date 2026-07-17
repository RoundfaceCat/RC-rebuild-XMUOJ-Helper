#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);          // 读取第一行字符串（可能含空格）
    char c;
    cin >> c;                 // 读取第二行待替换字符
    for (char &ch : s) {
        if (ch == c) ch = '#';
    }
    cout << s << endl;
    return 0;
}