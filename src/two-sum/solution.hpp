#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::map<int, int> cache;
        for (size_t i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (cache.find(complement) != cache.end()) {
                return {static_cast<int>(cache[complement]), static_cast<int>(i)};
            }
            cache[nums[i]] = i;
        }
        return {};
    }
};

#endif