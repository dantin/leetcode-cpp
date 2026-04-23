#include <iostream>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<int> nums{-1, 2, 1, -4};
    int target = 1;
    cout << "Input: nums = ";
    utils::print_container(nums);
    cout << ", target = " << target << endl;

    auto retval = s.threeSumClosest(nums, target);

    cout << "Output: " << retval << endl;
    cout << endl;

    vector<int> nums2{0, 0, 0};
    int target2 = 1;
    cout << "Input: nums = ";
    utils::print_container(nums2);
    cout << ", target = " << target2 << endl;

    auto retval2 = s.threeSumClosest(nums2, target2);

    cout << "Output: " << retval2 << endl;

    return 0;
}
