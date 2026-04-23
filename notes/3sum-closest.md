# 3Sum Closest Solution Explanation

## Problem Description

Given an integer array `nums` and an integer `target`, choose **three distinct indices** and minimize the absolute gap between their sum and `target`. Return **that sum** (not the indices). The problem statement guarantees a unique closest sum for each test case.

## Approach: Sorting + Two Pointers

Like classic 3Sum, we **sort** the array so that for a fixed first index `i`, we can sweep the remaining segment with **two pointers** `j` (low) and `k` (high) in linear time. The sort orders values so that increasing `j` raises the triple sum and decreasing `k` lowers it—exactly the monotonicity two pointers need.

### Algorithm Steps

1. **Small arrays**: If `nums.size() < 3`, the implementation returns `0` (a defensive branch; normal LeetCode constraints assume length ≥ 3).

2. **State for the answer**: `retval` holds the best triple sum seen so far; `min_diff` holds `|retval - target|` (initialized to `INT_MAX` so the first valid triple wins).

3. **Sort** `nums` ascending.

4. **Fix the first element** with index `i` from `0` to `n - 3`:
   - **Skip duplicate `i`**: If `i > 0` and `nums[i] == nums[i - 1]`, continue. Any triple using this `nums[i]` as the first value was already considered when the same value appeared at `i - 1` (with the same `j`/`k` range in principle). This only prunes redundant work; it does not change the optimal sum.

5. **Two pointers** on the sorted suffix: `j = i + 1`, `k = n - 1`, while `j < k`:
   - Compute `sum = nums[i] + nums[j] + nums[k]` and `diff = |sum - target|`.
   - If `diff < min_diff`, update `min_diff` and set `retval = sum`.
   - **Steer the pointers** using `sum` vs `target`:
     - If `sum < target`, the sum is too small; move `j` right to increase it.
     - If `sum > target`, the sum is too large; move `k` left to decrease it.
     - If `sum == target`, the distance is `0`, which is optimal; **return immediately** (early exit).

6. After all `(i, j, k)` combinations are explored, return `retval`.

### Why Two Pointers Work Here

After sorting, for fixed `i`, as `j` increases only and `k` decreases only, each move makes a deliberate choice: grow the sum or shrink it toward `target`. We never skip a configuration that could be strictly closer than what we already track, because any closer sum would still be reachable by continuing the pointer walk from the current `(j, k)` (standard invariant for “closest sum” variants).

### Duplicate Skip on `i`

Unlike full 3Sum, we do not need to deduplicate output triplets—only one numeric sum is returned. Skipping `i` when `nums[i]` equals the previous element avoids re-running essentially the same outer iteration; it is an optimization, not required for correctness on all inputs.

## Complexity Analysis

- **Time:** $\mathcal{O}(N^2)$ — sorting is $\mathcal{O}(N \log N)$; the double loop over `i` and the two-pointer scan is $\mathcal{O}(N^2)$ overall and dominates.
- **Space:** $\mathcal{O}(1)$ extra besides the input and the sort’s typical $\mathcal{O}(\log N)$ stack/recursion budget used by `std::sort`.

## Reference Implementation

The notes above describe the logic in `src/3sum-closest/solution.hpp` (`Solution::threeSumClosest`).
