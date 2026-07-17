#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    // 去除可能存在的前导零（题目说是正整数，但以防万一）
    auto strip = [](const string& s) -> string {
        size_t pos = s.find_first_not_of('0');
        if (pos == string::npos) return "0";
        return s.substr(pos);
    };
    a = strip(a);
    b = strip(b);

    vector<int> A, B;
    for (int i = (int)a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    for (int i = (int)b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');

    vector<int> C;
    int carry = 0;
    size_t n = max(A.size(), B.size());
    for (size_t i = 0; i < n; ++i) {
        int sum = carry;
        if (i < A.size()) sum += A[i];
        if (i < B.size()) sum += B[i];
        C.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry) C.push_back(carry);

    reverse(C.begin(), C.end());
    for (int x : C) cout << x;
    cout << '\n';

    return 0;
}