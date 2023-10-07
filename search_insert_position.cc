#include <iostream>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t lo = 0, hi = nums.size();

        while (lo < hi) {
            size_t mid = (lo + hi) / 2;
            if (nums[mid] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return (int) lo;
    }
};

int main()
{
    Solution s;
    vector<pair<vector<int>, int>> cases{
        {{1, 3, 5, 6}, 5},
        {{1, 3, 5, 6}, 2},
        {{1, 3, 5, 6}, 7},
    };

    for (auto &c : cases) {
        cout << "Input: nums = ";
        print_array(c.first);
        cout << ", target = " << c.second << endl;

        int retval = s.searchInsert(c.first, c.second);

        cout << "Output: " << retval << endl << endl;
    }

    return 0;
}
