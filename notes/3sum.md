# 3Sum Solution Explanation

## Problem Description
The goal is to find all unique triplets in an array that sum up to `0`. Duplicate triplets are not allowed in the final output.

## Approach: Sorting + Two Pointers

The most efficient and common approach to solve this problem is using a combination of **Sorting** and the **Two-Pointer** technique.

### Algorithm Steps

1. **Edge Case Handling**: If the array has fewer than 3 elements, we can immediately return an empty result since a triplet requires 3 elements.
2. **Sort the Array**: We first sort the input array `nums`. Sorting is crucial for two reasons:
   - It allows us to easily skip duplicate values to ensure our output triplets are unique.
   - It sets up the conditions where we can effectively use two pointers to find the target sum.
3. **Iterate and Fix One Element**: We iterate through the array using a primary pointer `i`. We fix `nums[i]` as the first element of our potential triplet.
   - **Skip Duplicates for `i`**: If `i > 0` and `nums[i] == nums[i - 1]`, we skip this iteration because we have already processed this element as the first part of a triplet. This prevents duplicate triplets.
4. **Two Pointers for the Remaining Two Elements**:
   - Initialize a left pointer `j = i + 1` (just after `i`) and a right pointer `k = nums.size() - 1` (at the end of the array).
   - While `j < k`, we calculate the `sum` of our three elements: `sum = nums[i] + nums[j] + nums[k]`.
   - **Case 1: `sum == 0`**: We found a valid triplet! 
     - Add `{nums[i], nums[j], nums[k]}` to our results.
     - Move both `j` and `k` (`++j` and `--k`).
     - **Skip Duplicates for `j` and `k`**: To avoid finding the same triplet again, we advance `j` while `nums[j] == nums[j - 1]` and decrement `k` while `nums[k] == nums[k + 1]`.
   - **Case 2: `sum < 0`**: The total sum is too small. Since the array is sorted, we can only increase the sum by moving the left pointer to the right (`++j`).
   - **Case 3: `sum > 0`**: The total sum is too large. We can only decrease the sum by moving the right pointer to the left (`--k`).

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N^2)$
  - Sorting the array takes $\mathcal{O}(N \log N)$.
  - The main loop iterates through the array taking $\mathcal{O}(N)$ time. Inside the loop, the two pointers `j` and `k` traverse the remaining elements taking $\mathcal{O}(N)$ time. This gives $\mathcal{O}(N) \times \mathcal{O}(N) = \mathcal{O}(N^2)$ for the inner nested operation.
  - Overall time complexity is dominated by the nested loops: $\mathcal{O}(N \log N) + \mathcal{O}(N^2) \approx \mathcal{O}(N^2)$.
- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N)$
  - Depending on the sorting algorithm implementation (e.g., `std::sort` in C++ usually takes $\mathcal{O}(\log N)$ space on average), the extra space is mostly related to the sorting. The algorithm itself requires $\mathcal{O}(1)$ auxiliary space if we disregard the space required to hold the output array.
