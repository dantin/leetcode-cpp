#include <iostream>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<int> nums{-1, 0, 1, 2, -1, -4};
    cout << "Input: " << endl;
    utils::print_container(nums);
    cout << endl;

    auto retval = s.threeSum(nums);

    cout << "Output: " << endl;
    cout << "[";
    for (size_t i = 0; i < retval.size(); ++i) {
        utils::print_container(retval[i]);
        if (i != retval.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
