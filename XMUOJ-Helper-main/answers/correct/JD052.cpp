#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int C;
    char op;
    cin >> C >> op;
    
    double sum = 0.0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            double x;
            cin >> x;
            if (j == C) {
                sum += x;
            }
        }
    }
    
    if (op == 'M') {
        sum /= 12.0;
    }
    
    printf("%.1f\n", sum);
    return 0;
}