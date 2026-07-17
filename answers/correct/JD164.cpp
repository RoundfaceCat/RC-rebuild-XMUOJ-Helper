#include <iostream>
using namespace std;

const int N = 20010;
int dp[N];

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        int vi, wi, s;
        cin >> vi >> wi >> s;
        for (int k = 1; k <= s; k *= 2) {
            for (int j = v; j >= k * vi; j--) {
                dp[j] = max(dp[j], dp[j - k * vi] + k * wi);
            }
            s -= k;
        }
        if (s > 0) {
            for (int j = v; j >= s * vi; j--) {
                dp[j] = max(dp[j], dp[j - s * vi] + s * wi);
            }
        }
    }
    cout << dp[v] << endl;
    return 0;
}