#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 大减小（保证 a >= b）
string sub(const string& a, const string& b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0) {
        int digitA = a[i] - '0';
        int digitB = (j >= 0) ? b[j] - '0' : 0;
        int diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res.push_back(diff + '0');
        --i;
        --j;
    }
    // 去除前导零
    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
}

bool less_than(const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b; // 字符串字典序比较，等长时与数值比较一致
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    bool neg = false;
    if (less_than(a, b)) {
        neg = true;
        swap(a, b);
    }
    string ans = sub(a, b);
    if (neg) cout << '-';
    cout << ans << '\n';
    return 0;
}