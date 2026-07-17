#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> perfects = {
        6,
        28,
        496,
        8128,
        33550336,
        8589869056,
        137438691328,
        2305843008139952128
    };
    for (long long p : perfects) {
        if (p <= N)
            cout << p << "\n";
    }
    return 0;
}