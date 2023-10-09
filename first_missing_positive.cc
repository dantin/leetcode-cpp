#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] <= 0) {
                nums[i] = size + 1;
            }
        }
        for (int i = 0; i < size; i++) {
            int n = abs(nums[i]);
            if (n <= size) {
                nums[n - 1] = -abs(nums[n - 1]);
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return size + 1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> cases{
        {1, 2, 0},
        {3, 4, -1, 1},
        {7, 8, 9, 11, 12},
    };

    for (auto nums : cases) {
        cout << "Input: nums = ";
        print_array(nums);
        cout << endl;

        int retval = s.firstMissingPositive(nums);

        cout << "Output: " << retval << endl << endl;
    }
    return 0;
}
