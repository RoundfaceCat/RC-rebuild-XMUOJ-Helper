#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long M, N;
    while (cin >> M >> N) {
        if (M == 0 && N == 0) break;
        if (M < 0 || N < 0) break;
        if (M > N) swap(M, N);
        long long sum = 0;
        for (long long i = M; i <= N; ++i) {
            cout << i << " ";
            sum += i;
        }
        cout << "Sum=" << sum << "\n";
    }
    return 0;
}