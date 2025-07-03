# Brent's Algorithm
Brent's Algorithm is used for cycle detection in iterated function sequences. It is an efficient method with time complexity O(μ + λ) and space complexity O(1), where:<br/>
μ is the index of the first element of the cycle<br/>
λ is the length of the cycle

# Algorithm: BrentCycleDetection
Input: Function f, initial value x₀<br/>
Output: μ (start index of cycle), λ (cycle length)<br/>

1: power ← 1<br/>
2: λ ← 1<br/>
3: tortoise ← x₀<br/>
4: hare ← f(x₀)<br/>
5: while tortoise ≠ hare do<br/>
6: &emsp;    if power == λ then<br/>
7: &emsp; &emsp;        tortoise ← hare<br/>
8: &emsp; &emsp;        power ← 2 × power<br/>
9: &emsp; &emsp;        λ ← 0<br/>
10:&emsp;    end if<br/>
11:&emsp;    hare ← f(hare)<br/>
12:&emsp;    λ ← λ + 1<br/>
13: end while<br/>
14: μ ← 0<br/>
15: tortoise ← x₀<br/>
16: hare ← x₀<br/>
17: for i ← 1 to λ do<br/>
18: &emsp;    hare ← f(hare)<br/>
19: end for<br/>
20: while tortoise ≠ hare do<br/>
21: &emsp;    tortoise ← f(tortoise)<br/>
22: &emsp;    hare ← f(hare)<br/>
23: &emsp;    μ ← μ + 1<br/>
24: end while<br/>
25: return (μ, λ)<br/>
