#include <stdio.h>
 
int st[100010], tt = 0;
 
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        while (tt && st[tt] >= x) tt--;
        if (tt) printf("%d ", st[tt]);
        else printf("-1 ");
        st[++tt] = x;
    }
    return 0;
}