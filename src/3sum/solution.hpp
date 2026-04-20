#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <algorithm>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> retval;
        if (nums.size() < 3) {
            return retval;
        }

        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            size_t j = i + 1;
            size_t k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    retval.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while (j < k && nums[j - 1] == nums[j]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
        }

        return retval;
    }
};

#endif
