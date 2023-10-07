#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> retval;
        size_t size = candidates.size();
        if (size == 0) {
            return retval;
        }
        vector<int> nums;
        dfs(retval, candidates, 0, size, nums, target);
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
        if (target < 0) {
            return;
        }
        if (target == 0) {
            retval.push_back(nums);
            return;
        }

        for (size_t i = begin; i < end; i++) {
            int n = candidates[i];
            nums.push_back(n);
            dfs(retval, candidates, i, end, nums, target - n);
            nums.pop_back();
        }
    }
};

int main()
{
    Solution s;

    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    cout << "Input: " << endl;
    print_nums(candidates);
    cout << ", target = " << target;
    cout << endl;

    auto retval = s.combinationSum(candidates, target);

    cout << "Output: " << endl;
    print_nums_array(retval);
    cout << endl;

    return 0;
}
