#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> retval;
        if (candidates.size() == 0 || target < 0) {
            return retval;
        }

        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        dfs(retval, candidates, 0, candidates.size(), nums, target);

        return retval;
    }

private:
    void dfs(
        vector<vector<int>> &retval,
        vector<int> &candidates,
        size_t begin,
        size_t end,
        vector<int> &nums,
        int target
    ) {
        if (target == 0) {
            retval.push_back(nums);
            return;
        }
        if (target < 0) {
            return;
        }
        for (size_t i = begin; i < end; i++) {
            int n = candidates[i];
            nums.push_back(n);
            dfs(retval, candidates, i + 1, end, nums, target - n);
            nums.pop_back();
            while (i < end - 1 && n == candidates[i + 1]) {
                ++i;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<pair<vector<int>, int>> cases{
        {{10, 1, 2, 7, 6, 1, 5}, 8},
        {{2, 5, 2, 1, 2}, 5},
    };

    for (auto c : cases) {
        vector<int> candidates = c.first;
        int target = c.second;

        cout << "Input: candidates = ";
        print_array(candidates);
        cout << ", target = " << target << endl;

        vector<vector<int>> retval = s.combinationSum2(candidates, target);

        cout << "Output:" << endl;
        print_nums_array(retval);
        cout << endl << endl;
    }

    return 0;
}
