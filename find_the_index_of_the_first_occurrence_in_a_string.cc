#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty()) {
            return -1;
        }

        size_t m = haystack.size(), n = needle.size();
        vector<int> match = kmpPreprocessing(needle);

        int j = -1;
        for (size_t i = 0; i< m; i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = match[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == (int)(n - 1)) {
                return (i - n + 1);
            }
        }
        return -1;
    }
private:
    vector<int> kmpPreprocessing(string s) {
        size_t n = s.size();
        vector<int> match(n, -1);

        int j = -1;
        for (size_t i = 1; i < n; i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = match[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            match[i] = j;
        }

        return match;
    }
};

int main()
{
    Solution s;
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << "Input: haystack = \"" << haystack << "\", needle = \"" << needle << "\"" << endl;

    int retval = s.strStr(haystack, needle);

    cout << "Output: " << retval << endl;

    return 0;
}
