#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, sz;
    cin >> n >> sz;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < sz; ++i) {
        if (i > 0) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';
    return 0;
}