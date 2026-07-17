import sys
import bisect

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    pos = 0
    n = data[pos]; m = data[pos + 1]
    pos += 2

    ops = []
    xs = set()
    for _ in range(n):
        x = data[pos]; c = data[pos + 1]
        pos += 2
        ops.append((x, c))
        xs.add(x)

    coords = sorted(xs)
    idx = {v: i for i, v in enumerate(coords)}
    size = len(coords)
    arr = [0] * size
    for x, c in ops:
        arr[idx[x]] += c

    pref = [0] * (size + 1)
    for i in range(size):
        pref[i + 1] = pref[i] + arr[i]

    out_lines = []
    remaining = len(data) - pos

    # 查询有两种可能：每行2个整数（l, r）或每行3个整数（l, r, c）
    if remaining == 2 * m:
        for _ in range(m):
            l = data[pos]; r = data[pos + 1]
            pos += 2
            left = bisect.bisect_left(coords, l)
            right = bisect.bisect_right(coords, r) - 1
            if left <= right:
                ans = pref[right + 1] - pref[left]
            else:
                ans = 0
            out_lines.append(str(ans))
    elif remaining == 3 * m:
        for _ in range(m):
            l = data[pos]; r = data[pos + 1]; _c = data[pos + 2]  # 忽略第三个整数
            pos += 3
            left = bisect.bisect_left(coords, l)
            right = bisect.bisect_right(coords, r) - 1
            if left <= right:
                ans = pref[right + 1] - pref[left]
            else:
                ans = 0
            out_lines.append(str(ans))
    else:
        # 备选：默认按每行2个整数处理
        for _ in range(m):
            l = data[pos]; r = data[pos + 1]
            pos += 2
            left = bisect.bisect_left(coords, l)
            right = bisect.bisect_right(coords, r) - 1
            if left <= right:
                ans = pref[right + 1] - pref[left]
            else:
                ans = 0
            out_lines.append(str(ans))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()