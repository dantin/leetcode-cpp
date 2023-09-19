#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int retval = 0;
        size_t n = s.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < (int) n; i++) {
            if (s[i] == ')') {
                int prev = 0;
                if (s[i - 1] == '(') {
                    prev = (i >= 2) ? dp[i - 2] : 0;
                    dp[i] = prev + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    prev = ((i - dp[i - 1]) >= 2) ? dp[i - dp[i - 1] - 2] : 0;
                    dp[i] = dp[i - 1] + prev + 2;
                }
            }
            retval = max(retval, dp[i]);
        }
        return retval;
    }
};

int main()
{
    Solution s;
    vector<string> cases{"(()", ")()()", ""};

    for (auto &str : cases ) {
        cout << "Input: \"" << str <<" \"" << endl;

        int retval = s.longestValidParentheses(str);

        cout << "Output: " << retval << endl << endl;
    }

    return 0;
}
