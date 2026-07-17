#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    int b;
    cin >> a >> b;

    // 处理乘以 0 的情况（题目已说明是正整数，但为鲁棒性保留）
    if (b == 0 || a == "0") {
        cout << "0\n";
        return 0;
    }

    vector<int> res(a.size() + 10, 0); // 预留足够空间
    int carry = 0;
    int pos = 0; // 当前结果位置（从低位开始）

    // 从 a 的最低位开始逐位乘
    for (int i = a.size() - 1; i >= 0; --i) {
        int digit = a[i] - '0';
        int prod = digit * b + carry;
        res[pos++] = prod % 10;
        carry = prod / 10;
    }

    // 处理剩余进位
    while (carry) {
        res[pos++] = carry % 10;
        carry /= 10;
    }

    // 移除前导零（pos 当前是有效长度）
    while (pos > 1 && res[pos - 1] == 0) {
        --pos;
    }

    // 逆序输出
    for (int i = pos - 1; i >= 0; --i) {
        cout << res[i];
    }
    cout << '\n';

    return 0;
}