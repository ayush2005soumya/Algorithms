#include <iostream>
#include <vector>
using namespace std;

vector<double> acornGenerator(vector<int> seeds, int m, int N) {
    int k = seeds.size() - 1;
    vector<vector<int>> X(N + 1, vector<int>(k + 1, 0));
    vector<double> U;

    X[0] = seeds;

    for (int n = 1; n <= N; ++n) {
        X[n][0] = X[n - 1][0];
        for (int j = 1; j <= k; ++j) {
            X[n][j] = (X[n - 1][j] + X[n][j - 1]) % m;
        }
        U.push_back(static_cast<double>(X[n][k]) / m);
    }

    return U;
}

int main() {
    vector<int> seeds = {1, 2, 3}; // k = 2
    int m = 10007;
    int N = 10;

    vector<double> randomNumbers = acornGenerator(seeds, m, N);
    cout << "Generated ACORN random numbers:\n";
    for (double num : randomNumbers)
        cout << num << "\n";

    return 0;
}
