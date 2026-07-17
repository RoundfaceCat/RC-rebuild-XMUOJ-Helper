#include <stdio.h>
#define MAXN 100010

typedef struct {
    int l, r;
} Interval;

Interval arr[MAXN];

// 按区间左端点升序排序
void sort_interval(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].l > arr[j+1].l)
            {
                Interval t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].l, &arr[i].r);
    }
    sort_interval(n);

    int cnt = 1;
    int now_r = arr[0].r;
    for (int i = 1; i < n; i++)
    {
        // 当前区间左端点 <= 上一个右端点，重叠/相邻，合并
        if (arr[i].l <= now_r)
        {
            if (arr[i].r > now_r)
                now_r = arr[i].r;
        }
        else
        {
            // 不重叠，新区间
            cnt++;
            now_r = arr[i].r;
        }
    }
    printf("%d\n", cnt);
    return 0;
}