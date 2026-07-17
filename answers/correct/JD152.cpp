#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool visited[N];

int main() {
    int n, m;
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (dist[u] == INF) {
            cout << "impossible" << endl;
            return 0;
        }
        res += dist[u];
        visited[u] = true;
        for (int v = 1; v <= n; v++) {
            dist[v] = min(dist[v], g[u][v]);
        }
    }
    cout << res << endl;
    return 0;
}