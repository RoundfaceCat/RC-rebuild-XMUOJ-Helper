#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> q;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(q.begin(), q.end(), a[i]);
        if (it == q.end()) {
            q.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << q.size() << endl;
    return 0;
}