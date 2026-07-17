#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // dp[j] = number of ways to partition j
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // base case: sum 0 has 1 way (empty set)
    
    // Complete knapsack: each number i can be used unlimited times
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    
    cout << dp[n] % MOD << '\n';
    return 0;
}