#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, V;
    cin >> N >> V;
    
    // dp[j] = maximum value using capacity j after processing some groups
    vector<long long> dp(V + 1, 0);
    
    for (int i = 0; i < N; ++i) {
        int S;
        cin >> S;
        vector<pair<int, long long>> items;
        items.reserve(S);
        for (int j = 0; j < S; ++j) {
            int v; long long w;
            cin >> v >> w;
            // ignore items heavier than the knapsack capacity
            if (v <= V) items.emplace_back(v, w);
        }
        if (items.empty()) continue; // no valid items in this group
        
        // ndp will hold the best value after considering this group
        // initially, we can choose to pick no item from this group
        vector<long long> ndp = dp;
        
        // for each item in the group, try to update ndp using the previous dp
        for (auto &it : items) {
            int v = it.first;
            long long w = it.second;
            // traverse capacity backwards to avoid using the same item twice
            for (int j = V; j >= v; --j) {
                if (dp[j - v] + w > ndp[j]) {
                    ndp[j] = dp[j - v] + w;
                }
            }
        }
        dp = move(ndp);
    }
    
    cout << dp[V] << "\n";
    return 0;
}