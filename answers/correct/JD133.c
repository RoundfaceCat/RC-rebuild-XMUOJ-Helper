#include <stdio.h>
#include <string.h>
#define MAXN 1005

int num[MAXN];   // 数字栈
char op[MAXN];   // 运算符栈
int ntop = 0, otop = 0;

// 获取运算符优先级
int get_prio(char c)
{
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
}

// 计算栈顶两个数，弹出，结果压回数字栈
void calc()
{
    int b = num[--ntop];
    int a = num[--ntop];
    char c = op[--otop];
    int res;
    if (c == '+') res = a + b;
    else if (c == '-') res = a - b;
    else if (c == '*') res = a * b;
    else if (c == '/') res = a / b;
    num[ntop++] = res;
}

int main()
{
    char s[MAXN];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        char ch = s[i];
        // 数字，处理多位数
        if (ch >= '0' && ch <= '9')
        {
            int x = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9')
            {
                x = x * 10 + s[i] - '0';
                i++;
            }
            i--;
            num[ntop++] = x;
        }
        else if (ch == '(')
        {
            op[otop++] = ch;
        }
        else if (ch == ')')
        {
            // 右括号，算到左括号
            while (op[otop - 1] != '(')
                calc();
            otop--; // 弹出左括号
        }
        else
        {
            // + - * /
            while (otop > 0 && get_prio(op[otop - 1]) >= get_prio(ch))
                calc();
            op[otop++] = ch;
        }
    }
    // 剩余运算符全部计算
    while (otop > 0)
        calc();
    printf("%d\n", num[0]);
    return 0;
}