#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> combination;

void backtrack(int start, int depth) {
    if (depth == k) {
        for (int i = 0; i < k; ++i) {
            if (i > 0) cout << ' ';
            cout << combination[i];
        }
        cout << '\n';
        return;
    }
    // 剪枝：剩余数字个数 (n - start + 1) 必须 >= (k - depth)
    for (int i = start; i <= n - (k - depth) + 1; ++i) {
        combination.push_back(i);
        backtrack(i + 1, depth + 1);
        combination.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    backtrack(1, 0);
    return 0;
}