#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    // 按左端点排序，如果左端点相同，按右端点（可省，用稳定的 sort 也没关系）
    sort(intervals.begin(), intervals.end());

    int groups = 0;
    int rmax = 0;
    bool first = true;
    for (auto &p : intervals) {
        int l = p.first, r = p.second;
        if (first) {
            groups = 1;
            rmax = r;
            first = false;
        } else {
            if (l <= rmax) { // 有交集，合并
                rmax = max(rmax, r);
            } else { // 无交集，新组
                ++groups;
                rmax = r;
            }
        }
    }

    cout << groups << endl;
    return 0;
}