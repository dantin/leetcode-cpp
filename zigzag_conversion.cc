#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string retval;
        auto n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (size_t j = 0; j + i < n; j += cycleLen) {
                retval += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    retval += s[j + cycleLen - i];
                }
            }
        }
        return retval;
    }

};

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
