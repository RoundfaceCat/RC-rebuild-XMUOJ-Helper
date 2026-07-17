#include <iostream>
using namespace std;

const int N = 100010;
int fa[N];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]); // 路径压缩
    return fa[x];
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        fa[b] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // 初始化父节点自己
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M')
        {
            unite(a, b);
        }
        else if (op == 'Q')
        {
            if (find(a) == find(b))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}