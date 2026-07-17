#include <iostream>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    
    if (B > A && D > A && (C + D) > (A + B) && C > 0 && A % 2 == 0) {
        std::cout << "Accepted\n";
    } else {
        std::cout << "Not accepted\n";
    }
    
    return 0;
}