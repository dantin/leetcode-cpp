#include <bits/stdc++.h>

#include "solution.hpp"

using namespace std;

int main()
{
    string str = "babad";
    cout << "Input: " << str << endl;

    Solution s;
    string retval = s.longestPalindrome(str);

    cout << "Output: " << retval << endl;

    return 0;
}
