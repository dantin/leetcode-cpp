#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <bits/stdc++.h>

class Solution {
   public:
    std::string longestPalindrome(std::string s)
    {
        int n = s.size();
        if (n == 0) {
            return "";
        }

        int maxLen = 1;
        int start = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);      // Odd length palindrome
            expandAroundCenter(i, i + 1);  // Even length palindrome
        }

        return s.substr(start, maxLen);
    }
};

#endif
