#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string retval("1");

        while (--n) {
            retval = getNext(retval);
        }

        return retval;
    }
private:
    string getNext(const string &s) {
        stringstream ss;
        auto i = s.begin();
        while (i != s.end()) {
            auto j = i;
            while (j != s.end() && *j == *i) {
                j++;
            }
            ss << distance(i, j) << *i;
            i = j;
        }
        return ss.str();
    }
};

int main()
{
    vector<int> cases{1, 4};
    Solution s;

    for (auto &n : cases) {
        cout << "Input: n = " << n << endl;

        string retval = s.countAndSay(n);

        cout << "Output: \"" << retval << "\"" << endl << endl;
    }
    return 0;
}
