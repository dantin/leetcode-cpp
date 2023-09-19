#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1) {
            return;
        }
        bool flag = false;
        for (size_t i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                swapWith(i - 1, nums, i);
                sort(nums.begin() + i, nums.end());
                flag = true;
                break;
            }
        }
        if (!flag) {
            sort(nums.begin(), nums.end());
        }
    }
private:
    void swapWith(size_t pos, vector<int> &nums, size_t i) {
        int min = nums[i];
        size_t idx = i;
        for (size_t j = i; j < nums.size(); j++) {
            if (min > nums[j] && nums[j] > nums[pos]) {
                idx = j;
                min = nums[j];
            }
        }
        swap(nums[idx], nums[pos]);
    }
};

int main()
{
    Solution s;

    vector<int> nums{1, 2, 3};
    cout << "Input: ";
    print_nums(nums);
    cout << endl;

    s.nextPermutation(nums);

    cout << "Output: ";
    print_nums(nums);
    cout << endl;

    return 0;
}
