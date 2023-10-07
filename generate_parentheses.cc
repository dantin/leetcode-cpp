#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> retval;
        generate(n, n, "", retval);

        return retval;
    }

private:
    void generate(int left, int right, string s, vector<string> &retval) {
        if (left == 0) {
            while (right--) {
                s += ")";
            }
            retval.push_back(s);
        } else if (right > left) {
            generate(left - 1, right, s + "(", retval);
            generate(left, right - 1, s + ")", retval);
        } else {
            generate(left - 1, right, s + "(", retval);
        }
    }
};

int main()
{
    Solution s;

    int n = 3;
    cout << "Input: n = " << n << endl;

    vector<string> retval = s.generateParenthesis(n);

    cout << "Output:" << endl;
    print_array(retval);
    cout << endl;

    return 0;
}
