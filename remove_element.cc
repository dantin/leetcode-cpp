#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int retval = 0;
        for (size_t i = 0; i< nums.size(); i++) {
            if (nums[i] != val) {
                nums[retval++] = nums[i];
            }
        }
        return retval;
    }
};

int main()
{
    Solution s;
    vector<int> nums{3, 2, 2, 3};
    int val = 3;

    cout << "Input: nums = ";
    print_array(nums);
    cout << ", val = " << val << endl;

    int retval = s.removeElement(nums, val);

    cout << "Output: " << retval << ", nums = ";
    print_array(nums);
    cout << endl;

    return 0;
}
