#include <iostream>
	#include <vector>
	using namespace std;
	const int MAXN = 100005;
	int fa[MAXN];
	int d[MAXN];
	// 带权并查集查找函数
	int find(int x) {
	    if (x != fa[x]) {
	        int root = find(fa[x]); // 递归找到根节点
	        d[x] = (d[x] + d[fa[x]]) % 3; // 更新当前节点到根节点的距离
	        fa[x] = root; // 路径压缩
	    }
	    return fa[x];
	}
	int main() {
	    // 优化输入输出流速度
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    int n, k;
	    if (!(cin >> n >> k)) return 0;
	    // 初始化并查集
	    for (int i = 1; i <= n; i++) {
	        fa[i] = i;
	        d[i] = 0;
	    }
	    int ans = 0;
	    for (int i = 0; i < k; i++) {
	        int op, y, z;
	        cin >> op >> y >> z;
	        // 越界或自己吃自己均为假话
	        if (y > n || z > n || (op == 2 && y == z)) {
	            ans++;
	            continue;
	        }
	        int ry = find(y);
	        int rz = find(z);
	        if (op == 1) { // y 和 z 是同类
	            if (ry == rz) {
	                // 若在同一个集合，判断同类关系是否成立
	                if (d[y] != d[z]) {
	                    ans++;
	                }
	            } else {
	                // 不在同一个集合，合并并设定关系
	                fa[ry] = rz;
	                d[ry] = (d[z] - d[y] + 3) % 3;
	            }
	        } else { // op == 2，y 吃 z
	            if (ry == rz) {
	                // 若在同一个集合，判断捕食关系是否成立
	                if ((d[y] - d[z] + 3) % 3 != 1) {
	                    ans++;
	                }
	            } else {
	                // 不在同一个集合，合并并设定关系
	                fa[ry] = rz;
	                d[ry] = (d[z] - d[y] + 1 + 3) % 3;
	            }
	        }
	    }
	    cout << ans << "\n";
	    return 0;
	}