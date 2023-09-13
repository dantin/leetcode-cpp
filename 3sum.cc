#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector <int> &nums) {
        vector<vector<int>> retval;
        if (nums.size() <= 2) {
            return retval;
        }

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; i++) {

        }

        return retval;
    }
};

int main()
{
    return 0;
}
