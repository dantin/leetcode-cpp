#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <string>
#include <unordered_map>

class Solution {
   public:
    int romanToInt(std::string s)
    {
        if (s.empty()) {
            return 0;
        }
        int retval = 0;
        retval = toInt(s[0]);
        for (size_t i = 1; i < s.length(); i++) {
            retval += toInt(s[i]);
            if (toInt(s[i - 1]) < toInt(s[i])) {
                retval -= toInt(s[i - 1]) * 2;
            }
        }
        return retval;
    }

   private:
    int toInt(char c)
    {
        // Enhanced with unordered_map for better maintainability and default value handling
        static const std::unordered_map<char, int> roman_map = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        auto it = roman_map.find(c);
        return (it != roman_map.end()) ? it->second : 0;  // Returns 0 as default for invalid chars

        // Alternative approach using count() and at():
        // return roman_map.count(c) ? roman_map.at(c) : 0;
    }
};

#endif
