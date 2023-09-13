#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s) {
        size_t n = s.size();

        // allocate dp and init.
        bool **dp = new bool*[n];
        for (size_t i = 0; i < n; i++) {
            dp[i] = new bool[n];
        }
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                dp[i][j] = false;
            }
        }

        // build dp table.
        size_t maxLen = 1;
        size_t start = 0;
        for (size_t i = 0; i < n; i++) {
            dp[i][i] = true;
            for (size_t j = 0; j < i; j++) {
                dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j+1][i-1]));
                if (dp[j][i] && maxLen < (i - j + 1)) {
                    maxLen = i - j + 1;
                    start = j;
                }
            }
        }

        // free memory.
        for (size_t i = 0; i < n; i++) {
            delete[] dp[i];
        }
        delete[] dp;

        return s.substr(start, maxLen);
    }
};

int main()
{
    string str = "babad";
    cout << "Input: " << str << endl;

    Solution s;
    string retval = s.longestPalindrome(str);

    cout << "Output: " << retval << endl;

    return 0;
}
