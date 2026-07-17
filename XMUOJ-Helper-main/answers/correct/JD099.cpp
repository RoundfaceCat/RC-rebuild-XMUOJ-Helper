#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> s1, s2; // s1用于入队，s2用于出队
    string op;

    while (cin >> op) {
        if (op == "push") {
            int x;
            cin >> x;
            s1.push(x);
        } else if (op == "pop") {
            // 如果s2为空，将s1全部倾倒入s2
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            // 题目保证pop时队列非空，直接输出s2栈顶
            cout << s2.top() << '\n';
            s2.pop();
        } else if (op == "empty") {
            if (s1.empty() && s2.empty())
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }

    return 0;
}