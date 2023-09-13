#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int retval = 0;
        int sign = 1;
        size_t i = 0;
        size_t n = s.length();

        while (s[i] == ' ' && i < n) {
            i++;
        }

        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        while (i < n) {
            if (s[i] < '0' || s[i] > '9') {
                break;
            }
            if (retval > INT_MAX / 10 || (retval == INT_MAX / 10 && (s[i] - '0' > INT_MAX % 10))) {
                return sign == -1 ? INT_MIN: INT_MAX;
            }
            retval = retval * 10 - '0' + s[i];
            i++;
        }

        return retval * sign;
    }
};

int main()
{
    Solution s;

    string str = "42";
    cout << "Input: " << str << endl;

    int retval = s.myAtoi(str);

    cout << "Output: " << retval << endl;

    return 0;
}
