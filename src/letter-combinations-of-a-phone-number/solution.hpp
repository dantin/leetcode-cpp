#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::vector<std::string> retval;
        if (digits.empty()) {
            return retval;
        }

        size_t cap = 1;
        for (char c : digits) {
            cap *= k_pad[static_cast<size_t>(c - '0')].size();
        }
        retval.reserve(cap);

        std::string path;
        path.reserve(digits.size());
        combinations(retval, path, digits, 0);
        return retval;
    }

   private:
    void combinations(std::vector<std::string>& retval, std::string& path,
                      const std::string& digits, size_t pos)
    {
        if (pos == digits.size()) {
            retval.push_back(path);
            return;
        }
        const size_t idx = static_cast<size_t>(digits[pos] - '0');
        for (char ch : k_pad[idx]) {
            path.push_back(ch);
            combinations(retval, path, digits, pos + 1);
            path.pop_back();
        }
    }

    static inline const std::vector<std::string> k_pad{
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
};

#endif
