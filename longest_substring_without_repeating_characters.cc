#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int retval = 0;
        int length = 0;

        size_t i = 0;
        while (i < s.size()) {
            const char c = s[i];
            if (window.find(c) == window.end()) {
                window[c] = i;
                length++;
                i++;
            } else {
                retval = max(retval, length);
                i = window[c] + 1;
                length = 0;
                window.clear();
            }
        }

        return max(retval, length);
    }
};

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
