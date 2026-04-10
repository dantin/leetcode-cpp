#include <iostream>
#include <string>

#include "solution.hpp"

using namespace std;

int main()
{
    string str = "PAYPALISHIRING";
    int numRows = 3;
    cout << "Input: s = " << str << ", numRows = " << numRows << endl;

    Solution s;
    string retval = s.convert(str, numRows);

    cout << "Output: " << retval << endl;

    return 0;
}
