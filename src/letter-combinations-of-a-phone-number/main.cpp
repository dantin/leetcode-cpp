#include <iostream>
#include <string>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;
    string digits = "23";
    cout << "Input: " << digits << endl;

    vector<string> retval = s.letterCombinations(digits);

    cout << "Output: ";
    utils::print_array(retval);
    cout << endl;
    return 0;
}
