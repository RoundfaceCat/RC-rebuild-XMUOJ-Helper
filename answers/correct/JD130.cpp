#include <iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 1;
}

void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k) {
    if (k == 0) {
        head = ne[head];
    } else {
        if (ne[k] != -1) {
            ne[k] = ne[ne[k]];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    while (cin >> m) {
        init();
        while (m--) {
            char op;
            cin >> op;
            if (op == 'H') {
                int x;
                cin >> x;
                add_to_head(x);
            } else if (op == 'D') {
                int k;
                cin >> k;
                remove(k);
            } else if (op == 'I') {
                int k, x;
                cin >> k >> x;
                add(k, x);
            }
        }
        bool first = true;
        for (int i = head; i != -1; i = ne[i]) {
            if (!first) cout << ' ';
            cout << e[i];
            first = false;
        }
        cout << '\n';
    }
    return 0;
}
