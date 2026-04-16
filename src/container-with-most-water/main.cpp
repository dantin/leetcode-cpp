#include <iostream>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Input: height = ";
    utils::print_array(height);
    cout << endl;

    int result = s.maxArea(height);

    cout << "Output: " << result << endl;

    return 0;
}
