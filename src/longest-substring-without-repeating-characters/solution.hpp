#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <bits/stdc++.h>

class Solution {
   public:
    int lengthOfLongestSubstring(std::string s)
    {
        int max_length = 0;
        // The character set consists of ASCII characters, so we only need an array of size 128
        // initialized to -1.
        std::vector<int> char_index(128, -1);
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (char_index[c] >= left) {
                left = char_index[c] + 1;
            }
            char_index[c] = right;
            max_length = std::max(max_length, right - left + 1);
        }
        return max_length;
    }
};

#endif
