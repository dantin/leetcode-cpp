#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> cache;
    for (size_t i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (cache.find(complement) != cache.end()) {
        return {static_cast<int>(cache[complement]), static_cast<int>(i)};
      }
      cache[nums[i]] = i;
    }
    return {};
  }
};

int main() {
  vector<pair<vector<int>, int>> cases{
      {{2, 7, 11, 15}, 9},
      {{3, 2, 4}, 6},
      {{3, 3}, 6},
  };
  Solution s;

  for (auto &c : cases) {
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
