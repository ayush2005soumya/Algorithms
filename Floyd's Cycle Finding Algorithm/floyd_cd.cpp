#include <iostream>
#include <functional>

std::pair<int, int> floyd(std::function<int(int)> f, int x0) {
    // Phase 1: Finding intersection point
    int tortoise = f(x0);
    int hare = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    // Phase 2: Finding the start of the cycle (mu)
    int mu = 0;
    tortoise = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }

    // Phase 3: Finding the cycle length (lambda)
    int lam = 1;
    hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        lam++;
    }

    return {mu, lam};
}

int main() {
    auto f = [](int x) { return (x * x + 1) % 255; };
    int x0 = 2;
    auto result = floyd(f, x0);
    std::cout << "Cycle starts at index: " << result.first << "\n";
    std::cout << "Cycle length: " << result.second << "\n";
    return 0;
}
