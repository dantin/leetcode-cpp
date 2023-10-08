#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() <= 2) {
            return -1;
        }

        int retval = 0;
        int distance = INT_MAX;

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; i++) {
            size_t j = i + 1;
            size_t k = nums.size() - 1;
            while (j < k) {
                int tmpSum = nums[i] + nums[j] + nums[k];
                int tmpDis;
                if (tmpSum < target) {
                    tmpDis = target - tmpSum;
                    if (tmpDis < distance) {
                        distance = tmpDis;
                        retval = nums[i] + nums[j] + nums[k];
                    }
                    ++j;
                } else if (tmpSum > target) {
                    tmpDis = tmpSum - target;
                    if (tmpDis < distance) {
                        distance = tmpDis;
                        retval = nums[i] + nums[j] + nums[k];
                    }
                    --k;
                } else {
                    retval = nums[i] + nums[j] + nums[k];
                    return retval;
                }
            }
        }
        return retval;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;

    cout << "Input: nums = ";
    print_array(nums);
    cout << ", target = " << target << endl;

    int retval = s.threeSumClosest(nums, target);

    cout << "Output: " << retval << endl;

    return 0;
}
