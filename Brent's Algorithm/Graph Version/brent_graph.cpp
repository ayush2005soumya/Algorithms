#include <iostream>
#include <vector>
#include <functional>

std::pair<int, int> brent_graph(const std::vector<int>& graph, int x0) {
    auto f = [&](int x) { return graph[x]; };
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
    // Graph: 0 → 1 → 2 → 3 → 4 → 2
    std::vector<int> graph = {1, 2, 3, 4, 2};
    int x0 = 0;

    std::pair<int, int> result = brent_graph(graph, x0);
    int mu = result.first;
    int lam = result.second;
    std::cout << "Cycle starts at index: " << mu << "\n";
    std::cout << "Cycle length: " << lam << "\n";

    return 0;
}
