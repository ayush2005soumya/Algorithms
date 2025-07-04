# Floyd’s Cycle-Finding Algorithm
## Goal:
Given a function f(x) and a starting value x0, find:<br/>
μ (mu): the start index of the cycle<br/>
λ (lambda): the length of the cycle<br/>
in a sequence like: x0, f(x0), f(f(x0)), ...<br/>

# Algorithm: FloydCycleDetection
Input: Function f, initial value x₀<br/>
Output: μ (start index of cycle), λ (length of cycle)<br/>

1: tortoise ← f(x₀)<br/>
2: hare ← f(f(x₀))<br/>
3: while tortoise ≠ hare do<br/>
4: &emsp;    tortoise ← f(tortoise)<br/>
5: &emsp;   hare ← f(f(hare))<br/>
6: end while<br/>
7: μ ← 0<br/>
8: tortoise ← x₀<br/>
9: while tortoise ≠ hare do<br/>
10:&emsp;    tortoise ← f(tortoise)<br/>
11:&emsp;    hare ← f(hare)<br/>
12:&emsp;    μ ← μ + 1<br/>
13: end while<br/>
14: λ ← 1<br/>
15: hare ← f(tortoise)<br/>
16: while tortoise ≠ hare do<br/>
17: &emsp;   hare ← f(hare)<br/>
18: &emsp;   λ ← λ + 1<br/>
19: end while<br/>
20: return (μ, λ)<br/>

# Comparison with Brent’s Algorithm

| Feature         | Floyd’s Algorithm                | Brent’s Algorithm  |
| --------------- | -------------------------------- | ------------------ |
| Function calls  | More (2 per loop)                | Fewer (1 per loop) |
| Memory usage    | O(1)                             | O(1)               |
| Speed (average) | Slower                           | Faster             |
| Concept         | Two pointers at different speeds | Power-doubling     |

