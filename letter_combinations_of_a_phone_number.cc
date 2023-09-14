#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> retval;
        vector<string> dictionary{
            " ",
            " ",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
        string cache;

        if (digits == "") {
            return retval;
        }

        combinations(retval, cache, digits, dictionary, 0);

        return retval;
    }

private:
    void combinations(vector<string> &retval, string tmp, string digits, vector<string> dictionary, size_t level) {
        if (level == digits.size()) {
            retval.push_back(tmp);
            return;
        }
        size_t n = digits[level] - '0';
        for (size_t i = 0; i < dictionary[n].size(); i++) {
            tmp.push_back(dictionary[n][i]);
            combinations(retval, tmp, digits, dictionary, level+1);
            tmp.pop_back();
        }
    }
};

int main()
{
    Solution s;
    string digits = "23";
    cout << "Input: " << digits << endl;

    vector<string> retval = s.letterCombinations(digits);

    cout << "Output: ";
    print_strs(retval);
    cout << endl;
    return 0;
}
