#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int>& a, int l, int r, int pivot_idx) {
    int pivot = a[pivot_idx];
    swap(a[pivot_idx], a[r]);
    int store = l;
    for (int i = l; i < r; ++i) {
        if (a[i] < pivot) {
            swap(a[i], a[store]);
            ++store;
        }
    }
    swap(a[store], a[r]);
    return store;
}

int quickselect(vector<int>& a, int l, int r, int k) {
    if (l == r) return a[l];
    int pivot_idx = l + rand() % (r - l + 1);
    int pi = partition(a, l, r, pivot_idx);
    if (pi == k) return a[pi];
    else if (pi > k) return quickselect(a, l, pi - 1, k);
    else return quickselect(a, pi + 1, r, k);
}

int main() {
    srand(time(0));
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << quickselect(a, 0, n - 1, k - 1) << endl;
    return 0;
}