#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> words;
    string s;
    while (cin >> s) {
        words.push_back(s);
    }
    string a, b;
    if (words.size() == 3) {
        // 第一行是整数k，忽略
        a = words[1];
        b = words[2];
    } else if (words.size() == 2) {
        a = words[0];
        b = words[1];
    } else {
        // 输入异常，认为不是子串
        cout << "no" << endl;
        return 0;
    }
    if (a.find(b) != string::npos) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}