#include <iostream>
#include <vector>

#include "solution.hpp"
#include "../utils.hpp"

using namespace std;

int main()
{
    vector<pair<vector<int>, vector<int>>> params{
        {{1, 3}, {2}},
        {{1, 2}, {3, 4}},
    };

    Solution s;
    for (auto it = params.begin(); it != params.end(); it++) {
        cout << endl;
        auto nums1 = it->first;
        auto nums2 = it->second;

        cout << "Input:" << endl;
        cout << " nums1 = ";
        utils::print_container(nums1);
        cout << endl;
        cout << " nums2 = ";
        utils::print_container(nums2);
        cout << endl;

        auto mid = s.findMedianSortedArrays(nums1, nums2);
        cout << "Output: " << mid << endl;
    }

    return 0;
}