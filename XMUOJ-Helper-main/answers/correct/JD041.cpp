#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    for (long long i = 1; i <= N; ++i) {
        for (long long j = 1; j <= M; ++j) {
            if (j > 1) cout << ' ';
            if (j == M) {
                cout << "SWORD";
            } else {
                cout << (i - 1) * M + j;
            }
        }
        cout << '\n';
    }
    return 0;
}