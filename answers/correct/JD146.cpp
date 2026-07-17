#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx; // 邻接表存储图
int d[N];     // 记录 1 号点到各个点的距离，初始化为 -1 表示未访问
int q[N];     // 模拟队列（手写队列比 std::queue 更快，适合 ACM/OJ）

// 添加一条边 a->b
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs() {
    int hh = 0, tt = 0; // 队列头尾指针
    q[0] = 1; // 起点 1 入队
    
    memset(d, -1, sizeof d); // 初始化距离数组为 -1
    d[1] = 0; // 起点到自己的距离是 0

    while (hh <= tt) {
        int t = q[hh++]; // 取出队头

        // 遍历 t 的所有出边
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i]; // j 是 t 能到达的点
            
            // 如果 j 还没有被访问过
            if (d[j] == -1) {
                d[j] = d[t] + 1;  // 更新距离
                q[++tt] = j;      // j 入队
            }
        }
    }

    return d[n]; // 返回 1 到 n 的距离，如果不可达，d[n] 依然是 -1
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h); // 初始化邻接表头为 -1

    // 读入 m 条边
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b); // 有向图，只存一次
    }

    cout << bfs() << endl;

    return 0;
}