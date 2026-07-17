#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double A, B, C;
    cin >> A >> B >> C;
    const double PI = 3.14159;
    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << (A * C / 2.0) << "\n";
    cout << "CIRCULO: " << (PI * C * C) << "\n";
    cout << "TRAPEZIO: " << ((A + B) * C / 2.0) << "\n";
    cout << "QUADRADO: " << (B * B) << "\n";
    cout << "RETANGULO: " << (A * B) << "\n";
    return 0;
}