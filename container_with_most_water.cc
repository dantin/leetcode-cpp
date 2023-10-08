#include <algorithm>
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int retval = 0;

        size_t left = 0;
        size_t right = height.size() - 1;
        while (left < right) {
            int area = min(height[left], height[right]) * (int)(right - left);
            retval = max(retval, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return retval;
    }
};

int main()
{
    Solution s;

    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Input: height = ";
    print_array(height);
    cout << endl;

    int retval = s.maxArea(height);

    cout << "Output: " << retval << endl;

    return 0;
}
