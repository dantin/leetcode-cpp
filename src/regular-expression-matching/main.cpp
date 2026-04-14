#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace std;

struct TestCase {
    string s;
    string p;
};

int main()
{
    Solution solution;

    vector<TestCase> cases = {
        {"aa", "a"}, {"aa", "a*"}, {"ab", ".*"}, {"aab", "c*a*b"}, {"mississippi", "mis*is*p*."},
        {"", "a*"},  {"a", "ab*"}};

    for (const auto& tc : cases) {
        cout << "Input: s = \"" << tc.s << "\", p = \"" << tc.p << "\"" << endl;
        bool retval = solution.isMatch(tc.s, tc.p);
        cout << "Output: " << (retval ? "true" : "false") << "\n" << endl;
    }

    return 0;
}
