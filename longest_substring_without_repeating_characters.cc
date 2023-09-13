#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int retval = 0;
        unordered_set<int> cache;

        size_t i = 0, j = 0;
        while (i < s.size() && j < s.size()) {
            if (!cache.count(s[j])) {
                cache.insert(s[j]);
                j++;
                retval = max(retval, (int)(j - i));
            } else {
                cache.erase(s[i]);
                i++;
            }
        }

        return retval;
    }
};

int main()
{
    string str = "abcabcbb";
    cout << "Input: " << str << endl;

    Solution s;
    int size = s.lengthOfLongestSubstring(str);
    cout << "Output: " << size << endl;

    return 0;
}
