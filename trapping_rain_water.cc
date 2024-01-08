#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }

        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int retval = 0;
        for (int i = 0; i < n; i++) {
            retval += min(leftMax[i], rightMax[i]) - height[i];
        }
        return retval;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> cases{
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
        {4, 2, 0, 3, 2, 5},
    };

    for (auto height : cases) {
        cout << "Input height = ";
        print_array(height);
        cout << endl;

        int retval = s.trap(height);

        cout << "Output: " << retval << endl << endl;
    }

    return 0;
}
