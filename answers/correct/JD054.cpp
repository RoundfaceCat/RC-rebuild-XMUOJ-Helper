#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    if (N < 2) return 0;
    
    vector<int> primes;
    vector<bool> is_prime(N + 1, true);
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) primes.push_back(i);
        for (int p : primes) {
            if (i * p > N) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;
        }
    }
    
    for (int x : primes) cout << x << '\n';
    return 0;
}