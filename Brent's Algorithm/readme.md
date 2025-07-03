# Brent's Algorithm
Brent's Algorithm is used for cycle detection in iterated function sequences. It is an efficient method with time complexity O(μ + λ) and space complexity O(1), where:
μ is the index of the first element of the cycle
λ is the length of the cycle

# Algorithm: BrentCycleDetection
Input: Function f, initial value x₀
Output: μ (start index of cycle), λ (cycle length)

1: power ← 1
2: λ ← 1
3: tortoise ← x₀
4: hare ← f(x₀)
5: while tortoise ≠ hare do
6:     if power == λ then
7:         tortoise ← hare
8:         power ← 2 × power
9:         λ ← 0
10:    end if
11:    hare ← f(hare)
12:    λ ← λ + 1
13: end while
14: μ ← 0
15: tortoise ← x₀
16: hare ← x₀
17: for i ← 1 to λ do
18:     hare ← f(hare)
19: end for
20: while tortoise ≠ hare do
21:     tortoise ← f(tortoise)
22:     hare ← f(hare)
23:     μ ← μ + 1
24: end while
25: return (μ, λ)
