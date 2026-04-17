#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <string>
#include <vector>

class Solution {
   public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty()) {
            return "";
        }

        for (size_t i = 0; i < strs[0].size(); i++) {
            for (size_t j = 1; j < strs.size(); j++) {
                // Check bounds before accessing character
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

#endif
