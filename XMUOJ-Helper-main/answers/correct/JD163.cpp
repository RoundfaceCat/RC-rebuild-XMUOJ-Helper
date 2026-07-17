#include <iostream>
using namespace std;

const int N = 2010;
int dp[N];

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        int vi, wi, s;
        cin >> vi >> wi >> s;
        for (int j = v; j >= vi; j--) {
            for (int k = 1; k <= s && k * vi <= j; k++) {
                dp[j] = max(dp[j], dp[j - k * vi] + k * wi);
            }
        }
    }
    cout << dp[v] << endl;
    return 0;
}