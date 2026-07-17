#include <iostream>
using namespace std;

const int N = 1010;
int dp[N];

int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        int vi, wi;
        cin >> vi >> wi;
        for (int j = vi; j <= v; j++) {
            dp[j] = max(dp[j], dp[j - vi] + wi);
        }
    }
    cout << dp[v] << endl;
    return 0;
}