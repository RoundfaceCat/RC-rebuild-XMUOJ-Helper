#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
vector<int> g[N];
int d[N];

bool topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }

    int cnt = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < g[t].size(); i++) {
            int j = g[t][i];
            if (--d[j] == 0) q.push(j);
        }
    }

    return cnt == n;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        d[b]++;
    }

    if (topsort()) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            cout << t << " ";

            for (int i = 0; i < g[t].size(); i++) {
                int j = g[t][i];
                if (--d[j] == 0) q.push(j);
            }
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}