#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long median = a[n / 2]; // 题中提示的下标 n/2

    long long sum = 0;
    for (long long x : a) {
        sum += abs(x - median);
    }

    cout << sum << '\n';
    return 0;
}