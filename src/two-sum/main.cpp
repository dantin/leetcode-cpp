#include <iostream>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    vector<pair<vector<int>, int>> cases{
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
    };
    Solution s;

    for (auto& c : cases) {
        vector<int> nums = c.first;
        int target = c.second;

        cout << "Input: nums = ";
        utils::print_array(nums);
        cout << ", target: " << target << endl;

        vector<int> retval = s.twoSum(nums, target);
        cout << "Output: ";
        utils::print_array(retval);
        cout << endl << endl;
    }

    return 0;
}