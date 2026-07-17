#include <cstdio>
#include <algorithm>

int main() {
    int N;
    while (std::scanf("%d", &N) == 1 && N != 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int val = std::min({i + 1, j + 1, N - i, N - j});
                std::printf("%3d", val);
            }
            std::printf("\n");
        }
        std::printf("\n");
    }
    return 0;
}