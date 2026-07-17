#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
vector<int> g[N]; // 邻接表存树
bool st[N];        // 记录节点是否被访问过
int ans = N;       // 全局答案，初始化为一个很大的数

// 返回以 u 为根的子树中节点的个数
int dfs(int u) {
    st[u] = true; // 标记 u 已经被访问

    int sum = 1;   // 当前子树总大小，包括 u 自己
    int res = 0;   // 去掉 u 之后，剩余各个连通块的最大值

    // 遍历 u 的所有子节点
    for (int i = 0; i < g[u].size(); i++) {
        int j = g[u][i];
        if (!st[j]) {
            int s = dfs(j);   // 递归计算 j 为根的子树大小
            res = max(res, s); // 更新 res（u 的某个子树的节点数）
            sum += s;          // 累加到总大小
        }
    }

    // 计算剩余的“父节点方向”的连通块大小
    res = max(res, n - sum);

    // 用当前状态下最大的连通块去更新全局最小值
    ans = min(ans, res);

    return sum;
}

int main() {
    cin >> n;
    // 读取 n-1 条边
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a); // 无向图，存两次
    }

    // 从任意节点开始搜索（这里从 1 开始）
    dfs(1);

    cout << ans << endl;

    return 0;
}