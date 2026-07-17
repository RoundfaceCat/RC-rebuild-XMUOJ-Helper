#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word, longest;
    while (iss >> word) {
        if (!word.empty() && word.back() == '.') {
            word.pop_back();   // 去掉末尾的句点
        }
        if (word.size() > longest.size()) {
            longest = word;
        }
    }
    cout << longest << endl;
    return 0;
}