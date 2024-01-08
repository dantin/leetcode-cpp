#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> retval;
        unordered_map<int, int> cache;
        for (int i = 0; (size_t)i < nums.size(); i++) {
            if (cache.find(target - nums[i]) != cache.end() && cache[target - nums[i]] != i) {
                retval.push_back(i);
                retval.push_back(cache[target - nums[i]]);
                break;
            }
            cache[nums[i]] = i;
        }
        return retval;
    }
};

int main()
{
    vector<pair<vector<int>, int>> cases{
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
    };
    Solution s;

    for (auto &c : cases) {
        vector<int> nums = c.first;
        int target = c.second;

        cout << "Input: nums = ";
        print_array(nums);
        cout << ", target: " << target << endl;

        vector<int> retval = s.twoSum(nums, target);
        cout << "Output: ";
        print_array(retval);
        cout << endl << endl;
    }

    return 0;
}
