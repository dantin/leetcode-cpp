#include <iostream>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<int> test_cases = {3749, 58, 1994};

    for (int num : test_cases) {
        cout << "Input: " << num << endl;
        cout << "Output: " << s.intToRoman(num) << endl;
        cout << endl;
    }

    return 0;
}
