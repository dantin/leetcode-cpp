#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        for (size_t i = 0; i < strs[0].size(); i++) {
            for (size_t j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main()
{
    Solution s;

    vector<string> strs{"flower", "flow", "flight"};
    cout << "Input: strs = ";
    print_array(strs);
    cout << endl;

    string retval = s.longestCommonPrefix(strs);

    cout << "Output: " << retval << endl;

    return 0;
}
