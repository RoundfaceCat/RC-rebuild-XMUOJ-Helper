#include <cstdio>

int main() {
    char op;
    scanf(" %c", &op);
    double a[12][12];
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            scanf("%lf", &a[i][j]);
    
    double sum = 0.0;
    int cnt = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < i; ++j) { // 主对角线以下，即 j < i
            sum += a[i][j];
            ++cnt;
        }
    }
    
    if (op == 'S') {
        printf("%.1f\n", sum);
    } else { // op == 'M'
        printf("%.1f\n", sum / cnt);
    }
    return 0;
}