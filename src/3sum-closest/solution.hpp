#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

class Solution {
   public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        if (nums.size() < 3) {
            return 0;
        }

        int retval = 0;
        int min_diff = std::numeric_limits<int>::max();

        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            size_t j = i + 1;
            size_t k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = std::abs(sum - target);

                if (diff < min_diff) {
                    min_diff = diff;
                    retval = sum;
                }

                if (sum < target) {
                    ++j;
                } else if (sum > target) {
                    --k;
                } else {
                    return sum;
                }
            }
        }
        return retval;
    }
};

#endif
