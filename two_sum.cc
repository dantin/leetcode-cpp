#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> retval;
        unordered_map<int, int> cache;
        for (int i = 0; (size_t) i < nums.size(); i++) {
            cache[nums[i]] = i;
        }
        for (int j = 0; (size_t)j < nums.size(); j++) {
            if (cache.find(target - nums[j]) != cache.end() && cache[target - nums[j]] != j) {
                retval.push_back(j);
                retval.push_back(cache[target - nums[j]]);
                break;
            }
        }
        return retval;
    }
};

void print_vector(vector<int> nums)
{
    cout << "[";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it;
        if ((it + 1) != nums.end()) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    cout << "Input: nums = ";
    print_vector(nums);
    cout << ", target: " << target << endl;

    Solution s;
    vector<int> retval = s.twoSum(nums, target);
    cout << "Output: ";
    print_vector(retval);
    cout << endl;

    return 0;
}
