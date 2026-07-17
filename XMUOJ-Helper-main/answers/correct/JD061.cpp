#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    char op;
    cin >> op;
    
    const int N = 12;
    vector<vector<double>> mat(N, vector<double>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
        }
    }
    
    double sum = 0.0;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i + j >= N) { // 反对角线以下（包含？题面说反对角线以下，提示说i+j>11，即>=12）
                sum += mat[i][j];
                ++cnt;
            }
        }
    }
    
    double ans = (op == 'S') ? sum : sum / cnt;
    cout << fixed << setprecision(1) << ans << endl;
    
    return 0;
}