#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector <int> &nums) {
        vector<vector<int>> retval;
        if (nums.size() <= 2) {
            return retval;
        }

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; i++) {
            size_t j = i + 1;
            size_t k = nums.size() - 1;
            while (j < k) {
                vector<int> pos;
                if (nums[i] + nums[j] + nums[k] == 0) {
                    pos.push_back(nums[i]);
                    pos.push_back(nums[j]);
                    pos.push_back(nums[k]);
                    retval.push_back(pos);
                    ++j;
                    --k;
                    while (j < k && nums[j - 1] == nums[j]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k+1]) {
                        --k;
                    }
                } else if(nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return retval;
    }
};

int main()
{
    Solution s;

    vector<int> nums{-1, 0, 1, 2, -1, -4};
    cout << "Input: " << endl;
    print_array(nums);
    cout << endl;

    auto retval = s.threeSum(nums);

    cout << "Output: " << endl;
    print_nums_array(retval);
    cout << endl;

    return 0;
}
