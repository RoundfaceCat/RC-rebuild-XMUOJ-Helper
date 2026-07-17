#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> divisors;
    for (long long i = 1; i <= N / i; ++i) {
        if (N % i == 0) {
            divisors.push_back(i);
            long long other = N / i;
            if (other != i) {
                divisors.push_back(other);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    for (long long d : divisors) {
        cout << d << "\n";
    }
    return 0;
}