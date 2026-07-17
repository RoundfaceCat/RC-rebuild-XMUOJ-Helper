// JD137: 堆石成丘 - Min-Heap with insertion-order tracking
#include <bits/stdc++.h>
using namespace std;

// 1-indexed heap
// ph[k] = position in heap of k-th inserted element
// hp[pos] = insertion index of element at heap position pos
struct Heap {
    vector<int> h;    // heap values, 1-indexed
    vector<int> ph;   // ph[k] = heap index of k-th inserted element
    vector<int> hp;   // hp[pos] = insertion index at heap position
    int sz, idx;

    Heap(int cap) : h(cap + 2), ph(cap + 2), hp(cap + 2), sz(0), idx(0) {}

    void swap_nodes(int a, int b) {
        swap(h[a], h[b]);
        swap(hp[a], hp[b]);
        ph[hp[a]] = a;
        ph[hp[b]] = b;
    }

    void sift_up(int k) {
        while (k > 1 && h[k] < h[k / 2]) {
            swap_nodes(k, k / 2);
            k /= 2;
        }
    }

    void sift_down(int k) {
        while (2 * k <= sz) {
            int j = 2 * k;
            if (j + 1 <= sz && h[j + 1] < h[j]) j++;
            if (h[k] > h[j]) {
                swap_nodes(k, j);
                k = j;
            } else break;
        }
    }

    void insert(int x) {
        idx++;
        sz++;
        h[sz] = x;
        ph[idx] = sz;
        hp[sz] = idx;
        sift_up(sz);
    }

    int query_min() { return h[1]; }

    void delete_min() {
        swap_nodes(1, sz);
        sz--;
        sift_down(1);
    }

    void delete_k(int k) {
        int pos = ph[k];
        swap_nodes(pos, sz);
        sz--;
        if (pos <= sz) {
            sift_up(pos);
            sift_down(pos);
        }
    }

    void change_k(int k, int x) {
        int pos = ph[k];
        h[pos] = x;
        sift_up(pos);
        sift_down(pos);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        Heap heap(n + 5);
        for (int i = 0; i < n; i++) {
            string cmd;
            cin >> cmd;
            if (cmd == "I") {
                int x; cin >> x;
                heap.insert(x);
            } else if (cmd == "PM") {
                cout << heap.query_min() << '\n';
            } else if (cmd == "DM") {
                heap.delete_min();
            } else if (cmd == "D") {
                int k; cin >> k;
                heap.delete_k(k);
            } else if (cmd == "C") {
                int k, x; cin >> k >> x;
                heap.change_k(k, x);
            }
        }
    }

    return 0;
}
