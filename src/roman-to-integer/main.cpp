#include <iostream>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<string> test_cases = {"III", "LVIII", "MCMXCIV"};

    for (const string& roman : test_cases) {
        cout << "Input: " << roman << endl;
        cout << "Output: " << s.romanToInt(roman) << endl;
        cout << endl;
    }

    return 0;
}