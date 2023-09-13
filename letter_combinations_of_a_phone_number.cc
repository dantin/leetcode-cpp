#include <iostream>
#include <string>
#include <vector>
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

void print_vector(vector<string> nums)
{
    cout << "[";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << "\"" << *it << "\"";
        if ((it + 1) != nums.end()) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    Solution s;
    string digits = "23";
    cout << "Input: " << digits << endl;

    vector<string> retval = s.letterCombinations(digits);

    cout << "Output: ";
    print_vector(retval);
    cout << endl;
    return 0;
}
