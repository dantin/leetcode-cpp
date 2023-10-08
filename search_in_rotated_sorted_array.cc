#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        size_t lo = 0, hi = nums.size();
        while (lo != hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return (int) mid;
            }
            if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[hi - 1]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;

    vector<pair<vector<int>, int>> cases{
        {{4, 5, 6, 7, 0, 1, 2}, 0},
        {{4, 5, 6, 7, 0, 1, 2}, 3},
        {{1, }, 0},
    };

    for (auto &c : cases) {
        cout << "Input: nums = ";
        print_array(c.first);
        cout << ", target = " << c.second << endl;

        int retval = s.search(c.first, c.second);

        cout << "Output: " << retval << endl << endl;
    }

    return 0;
}
