#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    while (getline(cin, s)) {
        if (s == ".") break;
        if (s.empty()) continue; // 跳过空行，若存在
        
        int len = s.size();
        vector<int> next(len, 0);
        
        // 计算 next 数组（前缀函数）
        for (int i = 1; i < len; ++i) {
            int j = next[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                ++j;
            }
            next[i] = j;
        }
        
        int L = len - next[len - 1]; // 最小可能周期
        int n = (len % L == 0) ? len / L : 1;
        cout << n << "\n";
    }
    
    return 0;
}