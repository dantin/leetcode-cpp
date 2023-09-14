#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> retval;
        if (nums.size() <= 3) {
            return retval;
        }

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (size_t j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                size_t k = j + 1;
                size_t l = nums.size() - 1;
                while (k < l) {
                    // avoid integer overflows and underflows.
                    long sum = 0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        vector<int> curr{nums[i], nums[j], nums[k], nums[l]};
                        retval.push_back(curr);
                        do {
                            ++k;
                        } while (k < l && nums[k] == nums[k - 1]);
                        do {
                            --l;
                        } while (k < l && nums[l] == nums[l + 1]);
                    } else if (sum < target) {
                        ++k;
                    } else {
                        --l;
                    }
                }
            }
        }

        return retval;
    }
};

int main()
{
    Solution s;

    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;

    cout << "Input: nums = ";
    print_nums(nums);
    cout << ", target = " << target << endl;

    vector<vector<int>> retval = s.fourSum(nums, target);

    cout << "Output:" << endl;
    print_nums_array(retval);
    cout << endl;

    return 0;
}
