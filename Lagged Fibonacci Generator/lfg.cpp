#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> laggedFibonacci(vector<int> seed, int j, int k, int m, int N, char op) {
    assert(j < k && k <= seed.size());
    vector<int> X = seed;
    vector<int> result;

    for (int n = 0; n < N; ++n) {
        int xj = X[X.size() - j];
        int xk = X[X.size() - k];
        int val;

        switch (op) {
            case '+': val = (xj + xk) % m; break;
            case '-': val = (xj - xk + m) % m; break;
            case '*': val = (xj * xk) % m; break;
            case '^': val = (xj ^ xk) % m; break;
            default: throw invalid_argument("Unsupported op");
        }

        X.push_back(val);
        result.push_back(val);
    }

    return result;
}

int main() {
    vector<int> seed = {1, 1, 2, 3, 5, 8, 13}; // length = k
    int j = 5, k = 7, m = 1000, N = 10;
    char op = '+';

    vector<int> output = laggedFibonacci(seed, j, k, m, N, op);
    cout << "Generated values:\n";
    for (int x : output)
        cout << x << " ";
    cout << endl;

    return 0;
}
