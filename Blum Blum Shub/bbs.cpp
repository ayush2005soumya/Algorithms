#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

vector<int> blumBlumShub(int p, int q, int seed, int n_bits) {
    assert(isPrime(p) && p % 4 == 3);
    assert(isPrime(q) && q % 4 == 3);

    long long M = 1LL * p * q;
    assert(seed > 1 && seed < M && seed % p != 0 && seed % q != 0);

    long long x = seed;
    vector<int> bits;

    for (int i = 0; i < n_bits; ++i) {
        x = (x * x) % M;
        bits.push_back(x % 2);
    }

    return bits;
}

int main() {
    int p = 499, q = 547;
    int seed = 159201;
    int n = 20;

    vector<int> bits = blumBlumShub(p, q, seed, n);
    cout << "Random bits: ";
    for (int b : bits) cout << b;
    cout << endl;

    return 0;
}
