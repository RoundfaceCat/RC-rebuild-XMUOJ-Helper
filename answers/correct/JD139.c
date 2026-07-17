#include <stdio.h>
#include <string.h>
 
#define N 100010
int p[N], sz[N];
 
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
 
void merge(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
        p[pa] = pb;
        sz[pb] += sz[pa];
    }
}
 
int main() {
    int n, m;
    if (scanf("%d%d", &n, &m) != 2) return 0;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    while (m--) {
        char op[4];
        scanf("%s", op);
        if (strcmp(op, "M") == 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            merge(a, b);
        } else if (strcmp(op, "C") == 0) {
            char rest[64];
            int a, b;
            fgets(rest, sizeof(rest), stdin);
            int cnt = sscanf(rest, "%d%d", &a, &b);
            if (cnt == 2) merge(a, b);
            else if (cnt == 1) printf("%d%c", sz[find(a)], 10);
        } else if (strcmp(op, "Q1") == 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            puts(find(a) == find(b) ? "Yes" : "No");
        } else if (strcmp(op, "Q2") == 0) {
            int a;
            scanf("%d", &a);
            printf("%d%c", sz[find(a)], 10);
        }
    }
    return 0;
}