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
        for (int i = 0; (size_t) i < nums.size(); i++) {
            cache[nums[i]] = i;
        }
        for (int j = 0; (size_t)j < nums.size(); j++) {
            if (cache.find(target - nums[j]) != cache.end() && cache[target - nums[j]] != j) {
                retval.push_back(j);
                retval.push_back(cache[target - nums[j]]);
                break;
            }
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
        print_nums(nums);
        cout << ", target: " << target << endl;

        vector<int> retval = s.twoSum(nums, target);
        cout << "Output: ";
        print_nums(retval);
        cout << endl << endl;
    }

    return 0;
}
