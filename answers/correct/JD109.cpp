#include <iostream>
#include <string>
using namespace std;

int popcountStr(const string& s) {
    // 去掉可能的前导符号（假设无符号或题目保证非负）
    string num = s;
    // 如果有负号，暂时去掉，按绝对值统计（若题目真有负数，需调整）
    if (!num.empty() && num[0] == '-') {
        num.erase(0, 1);
    }
    // 模拟除以2取余数
    int cnt = 0;
    while (num != "0") {
        // 判断奇偶：最后一位字符奇偶
        if ((num.back() - '0') % 2 == 1) cnt++;
        // 字符串除以2
        string next;
        int carry = 0;
        for (char ch : num) {
            int cur = carry * 10 + (ch - '0');
            int q = cur / 2;
            carry = cur % 2;
            if (!next.empty() || q != 0) {
                next.push_back(q + '0');
            }
        }
        if (next.empty()) next = "0";
        num = next;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    bool first = true;
    for (int i = 0; i < n; ++i) {
        string val;
        cin >> val;
        if (!first) cout << ' ';
        cout << popcountStr(val);
        first = false;
    }
    cout << '\n';
    return 0;
}