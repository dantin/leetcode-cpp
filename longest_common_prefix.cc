#include <iostream>
#include <string>
#include <vector>
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

void print_vector(vector<string> strs)
{
    cout << "[";
    for (auto it = strs.begin(); it != strs.end(); ++it) {
        cout << *it;
        if ((it + 1) != strs.end()) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    Solution s;

    vector<string> strs{"flower", "flow", "flight"};
    cout << "Input: strs = ";
    print_vector(strs);
    cout << endl;

    string retval = s.longestCommonPrefix(strs);

    cout << "Output: " << retval << endl;

    return 0;
}
