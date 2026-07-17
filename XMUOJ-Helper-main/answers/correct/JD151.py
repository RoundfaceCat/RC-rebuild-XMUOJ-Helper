import sys
data = list(map(int, sys.stdin.read().split()))
n, m, q = data[0], data[1], data[2]
INF = 10**18
dist = [[INF]*(n+1) for _ in range(n+1)]
for i in range(1, n+1):
    dist[i][i] = 0
idx = 3
for _ in range(m):
    a, b, w = data[idx], data[idx+1], data[idx+2]
    idx += 3
    if w < dist[a][b]:
        dist[a][b] = w
for k in range(1, n+1):
    for i in range(1, n+1):
        if dist[i][k] == INF:
            continue
        for j in range(1, n+1):
            nd = dist[i][k] + dist[k][j]
            if nd < dist[i][j]:
                dist[i][j] = nd
out = []
for _ in range(q):
    a, b = data[idx], data[idx+1]
    idx += 2
    d = dist[a][b]
    out.append(str(d) if d < INF//2 else "impossible")
sys.stdout.write('\n'.join(out))