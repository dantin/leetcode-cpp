#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <algorithm>
#include <vector>

class Solution {
   public:
    int maxArea(std::vector<int>& height)
    {
        int retval = 0;

        if (height.size() < 2) {
            return retval;
        }

        size_t left = 0;
        size_t right = height.size() - 1;
        while (left < right) {
            int area = std::min(height[left], height[right]) * (int)(right - left);
            retval = std::max(retval, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return retval;
    }
};

#endif
