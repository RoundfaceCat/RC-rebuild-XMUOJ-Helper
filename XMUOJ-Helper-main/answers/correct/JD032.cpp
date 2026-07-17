#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;
    
    long long start;
    if (x % 2 == 0) {
        start = x + 1;   // 偶数，从下一个奇数开始
    } else {
        start = x + 2;   // 奇数，跳过本身和下一个偶数
    }
    
    for (int i = 0; i < 6; ++i) {
        cout << start << '\n';
        start += 2;
    }
    
    return 0;
}