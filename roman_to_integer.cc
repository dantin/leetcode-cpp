#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int retval = 0;
        retval = toInt(s[0]);
        for (size_t i = 1; i < s.length(); i++) {
            retval += toInt(s[i]);
            if (toInt(s[i-1]) < toInt(s[i])) {
                retval -= toInt(s[i-1]) * 2;
            }
        }
        return retval;
    }
private:
    int toInt(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};

int main()
{
    Solution s;

    string str = "III";
    cout << "Input: " << str << endl;

    int retval = s.romanToInt(str);

    cout << "Output: " << retval << endl;

    return 0;
}
