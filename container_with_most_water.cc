#include <algorithm>
#include <iostream>
#include <vector>
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
    Solution s;

    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Input: height = ";
    print_vector(height);
    cout << endl;

    int retval = s.maxArea(height);

    cout << "Output: " << retval << endl;

    return 0;
}
