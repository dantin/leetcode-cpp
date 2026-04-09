#include <iostream>
#include <vector>
#include <string>

#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;
    vector<string> cases{"abcabcbb", "bbbbb", "pwwkew"};

    for (auto it = cases.begin(); it != cases.end(); ++it) {
        string str = *it;
        cout << "Input: " << str << endl;

        int size = s.lengthOfLongestSubstring(str);
        cout << "Output: " << size << endl << endl;
    }

    return 0;
}