#include <bits/stdc++.h>
using namespace std;

int main() {
    double sides[3];
    cin >> sides[0] >> sides[1] >> sides[2];
    
    // 降序排列，保证 sides[0] 是最大边
    sort(sides, sides + 3, greater<double>());
    double a = sides[0], b = sides[1], c = sides[2];
    
    // 判断是否能构成三角形
    if (a >= b + c) {
        cout << "Not a triangle" << endl;
        return 0;
    }
    
    // 根据最长边的平方与另外两边平方和的关系输出角类型
    double a2 = a * a, b2 = b * b, c2 = c * c;
    if (fabs(a2 - (b2 + c2)) < 1e-9)
        cout << "Right" << endl;
    else if (a2 > b2 + c2)
        cout << "Obtuse" << endl;
    else
        cout << "Acute" << endl;
    
    // 判断边类型并输出额外行（等边或等腰，不等边不输出）
    if (fabs(a - b) < 1e-9 && fabs(b - c) < 1e-9)
        cout << "Equilateral" << endl;
    else if (fabs(a - b) < 1e-9 || fabs(b - c) < 1e-9 || fabs(a - c) < 1e-9)
        cout << "Isosceles" << endl;
    
    return 0;
}