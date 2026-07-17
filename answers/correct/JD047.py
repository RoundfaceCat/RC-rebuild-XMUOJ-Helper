import sys

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return

    n = int(data[0])
    nums = list(map(int, data[1:1+n]))
    if n == 0:
        return
    min_val = min(nums)
    pos = nums.index(min_val)  # 返回第一个最小值的索引
    print(f"Menor valor: {min_val}")
    print(f"Posicao: {pos}")

if __name__ == "__main__":
    main()