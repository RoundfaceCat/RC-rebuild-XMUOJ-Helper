#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A;
    int B;
    cin >> A >> B;

    string quotient;
    int remainder = 0;

    for (char ch : A) {
        int digit = ch - '0';
        remainder = remainder * 10 + digit;
        int q = remainder / B;
        remainder %= B;
        quotient.push_back(q + '0');
    }

    // 去掉前导零，但保留至少一个数字
    size_t pos = quotient.find_first_not_of('0');
    if (pos == string::npos) {
        quotient = "0";
    } else {
        quotient = quotient.substr(pos);
    }

    cout << quotient << '\n' << remainder << '\n';

    return 0;
}