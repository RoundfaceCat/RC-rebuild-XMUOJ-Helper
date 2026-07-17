#include <stdio.h>
 
int a[1000010], q[1000010];
 
int main() {
    int n, k;
    if (scanf("%d%d", &n, &k) != 2) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && q[hh] <= i - k) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    putchar(10);
 
    hh = 0; tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && q[hh] <= i - k) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    return 0;
}