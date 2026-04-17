#include <iostream>
#include <string>
#include <vector>

#include "../utils.hpp"
#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<string> strs{"flower", "flow", "flight"};
    cout << "Input: strs = ";
    utils::print_array(strs);
    cout << endl;

    string retval = s.longestCommonPrefix(strs);

    cout << "Output: " << retval << endl;

    return 0;
}
