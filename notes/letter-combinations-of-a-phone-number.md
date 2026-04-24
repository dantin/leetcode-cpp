# Letter Combinations of a Phone Number — Solution Explanation

## Problem

Given a string of digits from `2`–`9` (a classic phone keypad), return every **letter combination** that the digits could represent, in the order a standard mapping would give. Digits `0` and `1` map to no letters in this model; if the input is empty, the answer is an empty list.

## Approach: Backtracking (depth-first search on the “digit index”)

We treat the problem as building all strings of length `digits.length()`: at position `level` we must pick one character from the set of letters for `digits[level]`, then recurse to the next index. When we have chosen a character for every digit, we record the built string and **backtrack** (remove the last character) so we can try the next option at the previous level.

A static mapping `k_pad[0..9]` stores the letters for each key; indices `0` and `1` are empty strings so that invalid keys produce no extra combinations if they appear in the input (in practice, LeetCode inputs are usually `2`–`9` only).

## Implementation Details

1. **Empty input**  
   If `digits` is empty, return an empty `vector` immediately (no work and no `""` combination).

2. **Capacity pre-allocation**  
   Before the search, the total number of combinations is the product, over all digits, of the number of letters for that key. The code reserves that many elements in the result vector to avoid repeated reallocations.

3. **Recursive `combinations`**  
   - **Base case:** `level == digits.size()` — the current `path` is one full combination; push a copy to the result and return.  
   - **Recursive case:** look up `digits[level]` in `k_pad`, iterate every character `ch`, append it to `path`, recurse with `level + 1`, then `pop_back` on `path` to restore state for the next `ch` (standard backtracking).

4. **Shared `path` buffer**  
   A single `std::string path` of length at most `digits.size()` is reused across the recursion, which keeps stack usage modest compared with passing new strings on every call.

## Complexity

- **Time:** $\mathcal{O}(3^N \cdot 4^M)$ in the analysis often written for this problem, where $N$ is the count of digits that map to 3 letters and $M$ to 4 (e.g. 7 and 9). In the worst case over typical inputs, each step branches up to 4 times for up to 4 such digits; more precisely it is the sum of the sizes of all leaves in the decision tree, i.e. proportional to the **number of output strings** times average work per string.
- **Space (auxiliary):** $\mathcal{O}(D)$ for the recursion stack and the `path` string, where $D = \text{digits.size()}$. The result vector itself holds all combinations and is not counted as auxiliary space in the usual LeetCode style.
