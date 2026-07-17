#include <iostream>
#include <map>
#include <string>

int main() {
    int ddd;
    std::cin >> ddd;

    const std::map<int, std::string> ddd_map = {
        {61, "Brasilia"},
        {71, "Salvador"},
        {11, "Sao Paulo"},
        {21, "Rio de Janeiro"},
        {32, "Juiz de Fora"},
        {19, "Campinas"},
        {27, "Vitoria"},
        {31, "Belo Horizonte"}
    };

    auto it = ddd_map.find(ddd);
    if (it != ddd_map.end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cout << "DDD nao cadastrado" << std::endl;
    }

    return 0;
}