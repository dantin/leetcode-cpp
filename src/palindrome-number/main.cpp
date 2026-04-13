#include <iostream>
#include <vector>

#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<int> cases = {121, -121, 10, 0, 11, 12321, 12345, 2147483647, 1001, -101};

    for (int n : cases) {
        cout << "Input: " << n << endl;
        bool retval = s.isPalindrome(n);
        cout << "Output: " << (retval ? "true" : "false") << "\n" << endl;
    }

    return 0;
}
