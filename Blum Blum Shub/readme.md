# Blum Blum Shub
The Blum Blum Shub (BBS) generator is a cryptographically secure pseudorandom number generator (CSPRNG) based on number theory. It is slow but highly secure, assuming factoring large numbers is hard.

# Blum Blum Shub (BBS) Overview
Recurrence Relation:
xₙ₊₁ = (xₙ)² mod M
Where:
M = p × q, and p ≡ 3 mod 4, q ≡ 3 mod 4, both primes.
x₀ is the seed, such that x₀ ∈ Zₘ and gcd(x₀, M) = 1.
Random Bit Output:
You can extract random bits from each xₙ using:
Least significant bit: xₙ % 2
Or multiple bits: xₙ & mask, xₙ % 256, etc.

# Pseudocode:

Algorithm BlumBlumShub<br/>
Input:<br/>
 &emsp;   - Primes p, q where p ≡ q ≡ 3 mod 4<br/>
 &emsp;   - Seed x₀ ∈ Zₘ, gcd(x₀, M) = 1<br/>
 &emsp;   - n = number of random bits required<br/>

Output: Bitstring B of length n<br/>

1: M ← p × q<br/>
2: x ← x₀<br/>
3: B ← empty string<br/>

4: for i = 1 to n do<br/>
5: &emsp;    x ← (x × x) mod M<br/>
6: &emsp;    b ← x mod 2         // extract least significant bit<br/>
7: &emsp;    Append b to B<br/>
8: end for<br/>

9: return B<br/>
