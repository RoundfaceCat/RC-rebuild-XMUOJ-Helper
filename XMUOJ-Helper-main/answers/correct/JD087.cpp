#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, size;
    cin >> n >> size;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // 防止 size 超过 n
    if (size > n) size = n;
    
    // 翻转前 size 个元素
    reverse(a.begin(), a.begin() + size);
    
    // 输出
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    
    return 0;
}