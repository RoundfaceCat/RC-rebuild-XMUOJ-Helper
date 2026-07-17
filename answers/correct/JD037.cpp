#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A;
    cin >> A;
    
    long long N = 0;
    long long x;
    while (cin >> x) {
        if (x > 0) {
            N = x;
            break;
        }
    }
    
    // 计算从A开始的N个连续整数和
    long long sum = N * A + N * (N - 1) / 2;
    cout << sum << endl;
    
    return 0;
}