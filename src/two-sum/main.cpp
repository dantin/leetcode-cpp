#include <iostream>
#include <vector>
#include <string>

#include "solution.hpp"

using namespace std;

template <typename T>
void print_array(const vector<T>& v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if constexpr (is_same_v<T, string>) {
            cout << "'" << v[i] << "'";
        } else {
            cout << v[i];
        }
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    vector<pair<vector<int>, int>> cases{
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6},
    };
    Solution s;

    for (auto& c : cases) {
        vector<int> nums = c.first;
        int target = c.second;

        cout << "Input: nums = ";
        print_array(nums);
        cout << ", target: " << target << endl;

        vector<int> retval = s.twoSum(nums, target);
        cout << "Output: ";
        print_array(retval);
        cout << endl << endl;
    }

    return 0;
}