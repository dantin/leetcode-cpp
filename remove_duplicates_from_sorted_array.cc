#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        size_t pos = 0;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[++pos] = nums[i + 1];
            }
        }
        
        return (int)(pos + 1);
    }
};

int main()
{
    vector<int> nums{1, 1, 2};
    cout << "Input: nums = ";
    print_array(nums);
    cout << endl;

    Solution s;
    int retval = s.removeDuplicates(nums);

    cout << "Output: " << retval << ", nums = ";
    print_array(nums);
    cout << endl;

    return 0;
}
