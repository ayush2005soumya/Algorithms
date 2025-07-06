# What is the ACORN Generator?
ACORN stands for:

Additive Congruential Random Number Generator

It generates a sequence of pseudo-random numbers using the recurrence:

plaintext
X[n][j] = (X[n-1][j] + X[n][j-1]) mod m
Where:

X[n][j] is the nth row and jth column of the generated table.

m is the modulus (usually a large prime or power of 2).

X[0][j] are initial seeds (for j = 0 to k, where k is the order of the generator).

The final random number is typically:

plaintext
U_n = X[n][k] / m   ∈ [0,1)

# Pseudocode for ACORN Generator
Algorithm ACORN(k, m, N)<br/>
Input: <br/>
 &emsp;   k ← order of the generator<br/>
 &emsp;   m ← modulus<br/>
 &emsp;   N ← number of random numbers to generate<br/>
 &emsp;   seeds ← initial seed values [X[0][0], X[0][1], ..., X[0][k]]<br/>

Output: <br/>
 &emsp;   U ← array of pseudo-random numbers in [0, 1)<br/>

1: Create array X[0..N][0..k]<br/>
2: Set X[0][j] ← seeds[j], for j = 0 to k<br/>
3: for n = 1 to N do<br/>
4: &emsp;    X[n][0] ← X[n-1][0]<br/>
5: &emsp;    for j = 1 to k do<br/>
6: &emsp;&emsp;        X[n][j] ← (X[n-1][j] + X[n][j-1]) mod m<br/>
7: &emsp;    end for<br/>
8: &emsp;    U[n] ← X[n][k] / m<br/>
9: end for<br/>
10: return U<br/>

# Properties of ACORN

| Property         | Value                                 |
| ---------------- | ------------------------------------- |
| Type             | Additive Congruential Generator       |
| Period           | High (depends on `m`, `k`)            |
| Speed            | Very fast (additions only)            |
| Space Complexity | O(N × k)                              |
| Suitable for     | Simulation, statistics, parallel RNGs |

