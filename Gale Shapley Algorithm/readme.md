# Gale-Shapley Algorithm
Also called the Stable Marriage Algorithm, it finds a stable matching between two equally sized sets (e.g., men and women), given their preferences.

# Problem Statement:
Given n men and n women, where each person ranks all members of the opposite set in order of preference, find a stable matching such that:
No pair (man, woman) prefers each other over their current partners.

# Pseudocode:
Algorithm GaleShapley<br/>
Input: <br/>
 &emsp;    - List of men M = {m₁, ..., mn}<br/>
 &emsp;    - List of women W = {w₁, ..., wn}<br/>
 &emsp;    - Each man m has a preference list over W<br/>
 &emsp;    - Each woman w has a preference list over M<br/>

Output: Stable matching pairs<br/>

1: Initialize all men and women as free<br/>
2: while ∃ free man m who hasn’t proposed to every woman do<br/>
3: &emsp;     w ← m's highest-ranked woman to whom he has not yet proposed<br/>
4: &emsp;     if w is free then<br/>
5: &emsp; &emsp;         (m, w) become engaged<br/>
6: &emsp;     else<br/>
7:  &emsp; &emsp;        m' ← w's current partner<br/>
8:  &emsp; &emsp;        if w prefers m over m' then<br/>
9: &emsp; &emsp;  &emsp;            (m, w) become engaged<br/>
10: &emsp; &emsp; &emsp;            m' becomes free<br/>
11: &emsp; &emsp;        else<br/>
12: &emsp; &emsp; &emsp;            m remains free<br/>
13: &emsp; &emsp;        end if<br/>
14: &emsp;    end if<br/>
15: end while<br/>
16: return all engaged pairs<br/>

# Summary

| Feature          | Value                                        |
| ---------------- | -------------------------------------------- |
| Time Complexity  | O(n²)                                        |
| Space Complexity | O(n²)                                        |
| Guarantees       | Stable matching                              |
| Applications     | College admission, job-market matching, etc. |
