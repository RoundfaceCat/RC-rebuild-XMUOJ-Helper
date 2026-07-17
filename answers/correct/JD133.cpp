#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 获取运算符优先级
int priority(char op)
{
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

// 计算两个数 op 运算结果
int calc(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int main()
{
    string s;
    cin >> s;
    stack<int> num;
    stack<char> op;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        // 数字，处理多位数
        if (c >= '0' && c <= '9')
        {
            int x = 0;
            int j = i;
            while (j < n && s[j] >= '0' && s[j] <= '9')
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            num.push(x);
            i = j - 1;
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == ')')
        {
            // 直到左括号
            while (op.top() != '(')
            {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char o = op.top(); op.pop();
                num.push(calc(a, b, o));
            }
            op.pop(); // 弹出左括号
        }
        else // + - * /
        {
            // 当前优先级 <= 栈顶，先计算
            while (!op.empty() && priority(c) <= priority(op.top()))
            {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                char o = op.top(); op.pop();
                num.push(calc(a, b, o));
            }
            op.push(c);
        }
    }
    // 剩余运算符全部计算
    while (!op.empty())
    {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char o = op.top(); op.pop();
        num.push(calc(a, b, o));
    }
    cout << num.top() << endl;
    return 0;
}