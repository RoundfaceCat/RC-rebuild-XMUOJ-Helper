#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // 读取所有元素 (long long 以支持大整数)
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // tails 数组：tails[i] 表示长度为 i+1 的递增子序列的最小可能末尾元素
    vector<long long> tails;
    tails.reserve(n);

    for (long long x : a) {
        // 在 tails 中二分查找第一个 >= x 的位置
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            // 当前 x 比所有 tails 元素都大，可扩展最长子序列
            tails.push_back(x);
        } else {
            // 否则用更小的 x 替换该位置，保持 tails 数组尽可能小
            *it = x;
        }
    }

    // tails 的大小即为最长严格递增子序列的长度
    cout << tails.size() << '\n';

    return 0;
}