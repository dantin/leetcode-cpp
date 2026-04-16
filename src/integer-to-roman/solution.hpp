#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <string>
#include <vector>

class Solution {
   public:
    std::string intToRoman(int num)
    {
        const std::vector<int> radix = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const std::vector<std::string> symbol = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                                 "XL", "X",  "IX", "V",  "IV", "I"};

        std::string retval;
        for (size_t i = 0; i < radix.size() && num > 0; i++) {
            int c = num / radix[i];
            num %= radix[i];
            while (c > 0) {
                retval += symbol[i];
                c--;
            }
        }

        return retval;
    }
};

#endif
