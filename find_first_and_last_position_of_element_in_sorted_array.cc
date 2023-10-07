#include <iostream>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> retval{-1, -1};

        size_t left = binarySearch(nums, target, true);
        if (left == nums.size() || nums[left] != target) {
            return retval;
        }
        retval[0] = (int) left;
        retval[1] = ((int) binarySearch(nums, target, false)) - 1;
        return retval;
    }

private:
    size_t binarySearch(vector<int> nums, int target, bool left) {
        size_t lo = 0, hi = nums.size();
        while (lo < hi) {
            size_t mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};

int main()
{
    Solution s;
    vector<pair<vector<int>, int>> cases {
        {{5, 7, 7, 8, 8, 10}, 8},
        {{5, 7, 7, 8, 8, 10}, 6},
        {{}, 0},
    };

    for (auto &c : cases) {
        cout << "Input: nums = ";
        print_array(c.first);
        cout << ", target = " << c.second << endl;

        vector<int> retval = s.searchRange(c.first, c.second);

        cout << "Output: ";
        print_array(retval);
        cout << endl << endl;
    }
    return 0;
}
