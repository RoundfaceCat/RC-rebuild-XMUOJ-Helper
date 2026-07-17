#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string text, wordA, wordB;
    getline(cin, text);
    getline(cin, wordA);
    getline(cin, wordB);
    
    string result;
    int n = (int)text.size();
    int i = 0;
    while (i < n) {
        if (isspace(text[i])) {
            result += text[i];
            ++i;
            continue;
        }
        int j = i;
        while (j < n && !isspace(text[j])) {
            ++j;
        }
        string token = text.substr(i, j - i);
        if (token == wordA) {
            result += wordB;
        } else {
            result += token;
        }
        i = j;
    }
    
    cout << result << '\n';
    return 0;
}