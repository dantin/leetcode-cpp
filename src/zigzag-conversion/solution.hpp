#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <string>
#include <vector>

class Solution {
   public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1) {
            return s;
        }

        std::string retval;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                retval += s[j + i];
                // For middle rows, add the diagonal character
                if (i != 0 && i != numRows - 1) {
                    int diagonalIdx = j + cycleLen - i;
                    if (diagonalIdx < n) {
                        retval += s[diagonalIdx];
                    }
                }
            }
        }
        return retval;
    }
};

#endif
