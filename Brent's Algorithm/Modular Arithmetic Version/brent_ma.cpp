#include <iostream>
#include <functional>

std::pair<int, int> brent_modular(std::function<int(int)> f, int x0) {
    int power = 1, lam = 1;
    int tortoise = x0;
    int hare = f(x0);

    while (tortoise != hare) {
        if (power == lam) {
            tortoise = hare;
            power *= 2;
            lam = 0;
        }
        hare = f(hare);
        ++lam;
    }

    int mu = 0;
    tortoise = hare = x0;
    for (int i = 0; i < lam; ++i)
        hare = f(hare);

    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        ++mu;
    }

    return {mu, lam};
}

int main() {
    int mod = 97;
    auto f = [mod](int x) { return (x * x + 1) % mod; };
    int x0 = 10;

    std::pair<int, int> result = brent_modular(f, x0);
    int mu = result.first;
    int lam = result.second;
    std::cout << "Cycle starts at index: " << mu << "\n";
    std::cout << "Cycle length: " << lam << "\n";

    return 0;
}
