#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> tri(n);
    for (int i = 0; i < n; i++) {
        tri[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    // Bottom-up DP
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }
    cout << tri[0][0] << "\n";
    return 0;
}
