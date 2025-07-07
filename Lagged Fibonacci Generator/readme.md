# Lagged Fibonacci Generator (LFG)
General Form:
X[n] = (X[n - j] op X[n - k]) mod m
Where:

op ∈ {+, −, ×, ⊕ (XOR)}

j < k are the lags

m is the modulus

Seed array must have at least k elements

LFG is used in libraries like Numerical Recipes, and with proper tuning, it produces high-quality random numbers.

# Pseudocode:
Algorithm LaggedFibonacciGenerator<br/>
Input:<br/>
&emsp;    - Integers j, k such that 0 < j < k<br/>
&emsp;    - Modulus m<br/>
&emsp;    - Operation op ∈ {+, −, *, XOR}<br/>
&emsp;    - Seed array S[0..k−1]<br/>
&emsp;    - Number of outputs N<br/>

Output:<br/>
&emsp;    - Array R[0..N−1] of pseudo-random numbers<br/>

1: Initialize array X[0..k−1] ← S<br/>
2: for n = k to k + N − 1 do<br/>
3: &emsp;    if op == '+':<br/>
4: &emsp;&emsp;        X[n] ← (X[n−j] + X[n−k]) mod m<br/>
5: &emsp;    else if op == '-':<br/>
6: &emsp;&emsp;        X[n] ← (X[n−j] − X[n−k]) mod m<br/>
7: &emsp;    else if op == '*':<br/>
8: &emsp;&emsp;        X[n] ← (X[n−j] × X[n−k]) mod m<br/>
9: &emsp;    else if op == 'XOR':<br/>
10:&emsp;&emsp;        X[n] ← (X[n−j] XOR X[n−k]) mod m<br/>
11:&emsp;    end if<br/>
12: end for<br/>
13: return X[k..k+N−1]<br/>

# NOtes and Varients:
| Name           | Operation | Common               |
| -------------- | --------- | -------------------- |
| Additive       | `+`       | Yes                  |
| Multiplicative | `*`       | Rare                 |
| XOR            | `^`       | Used in cryptography |
| Subtractive    | `-`       | Less common          |

# Properties:
| Feature                   | Value                                 |
| ------------------------- | ----------------------------------    |
| Speed                     | Fast                                  |
| Period                    | Very large (depends on `m`, `k`)      |
| Use-case                  | Simulations, games, math libs         |
| Cryptographically Secure? | ❌ No (use BBS or ChaCha20 instead)   |
