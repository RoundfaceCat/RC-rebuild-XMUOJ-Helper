#include <iostream>
 
using namespace std;
 
const int N = 100010;
 
int stk[N], tt;
 
int main()
 
{
 
    int n;
 
    cin >> n;
    while (n -- )
 
    {
 
        int x;
 
        scanf("%d", &x);
 
        while (tt && stk[tt] >= x) tt -- ;  //从它往左边走
 
        if (!tt) printf("-1 ");  //如果最后是 0 ，输出 -1  
 
        else printf("%d ", stk[tt]);  
 
        stk[ ++ tt] = x;  //记载这个数字
 
    }
 
    return 0;
 
}