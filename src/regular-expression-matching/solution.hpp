#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <string>
#include <vector>

class Solution {
   public:
    bool isMatch(std::string s, std::string p)
    {
        int m = s.length();
        int n = p.length();

        // dp[i][j] represents if the first i characters in s match the first j characters in p
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Base cases: empty string matching patterns with '*'
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.') {
                        // The '*' means zero occurrences of the preceding element
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        // The '*' means zero or more occurrences of the preceding element
                        // dp[i][j - 2] -> zero occurrences
                        // dp[i - 1][j] -> one or more occurrences (since s[i-1] matches p[j-2])
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

#endif
