#include <iostream>

int main() {
    int N;
    std::cin >> N;
    std::cout << N << "\n";

    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < 7; ++i) {
        int qtd = N / notas[i];
        N %= notas[i];
        std::cout << qtd << " nota(s) de R$ " << notas[i] << ",00\n";
    }

    return 0;
}