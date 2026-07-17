#include <bits/stdc++.h>
using namespace std;

const int N = 300010;

typedef pair<int, int> PII;

int n, m;
vector<int> alls;          // 存所有需要离散化的坐标
vector<PII> add_ops;       // 存修改操作：x, c
vector<PII> query_ops;     // 存查询操作：l, r

long long a[N], s[N];

// 找到 x 离散化后的下标，从 1 开始
int find_idx(int x) {
    int l = 0, r = alls.size() - 1;

    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l + 1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;

        add_ops.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        query_ops.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    // 排序去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 处理加法操作
    for (auto op : add_ops) {
        int x = op.first;
        int c = op.second;

        int idx = find_idx(x);
        a[idx] += c;
    }

    // 求前缀和
    for (int i = 1; i <= (int)alls.size(); i++) {
        s[i] = s[i - 1] + a[i];
    }

    // 回答查询
    for (auto q : query_ops) {
        int l = q.first;
        int r = q.second;

        int left = find_idx(l);
        int right = find_idx(r);

        cout << s[right] - s[left - 1] << '\n';
    }

    return 0;
}