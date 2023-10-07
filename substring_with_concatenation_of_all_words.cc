#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> retval;
        if (s.empty() || words.empty()) {
            return retval;
        }
        size_t m = words.size();
        size_t n = words[0].size();
        size_t total = s.size();

        for (size_t i = 0; i < n && i + m * n <= total; i++) {
            unordered_map<string, int> cache;
            for (size_t j = 0; j < m; j++) {
                ++cache[s.substr(i + j * n, n)];
            }
            for (string &word: words) {
                if (--cache[word] == 0) {
                    cache.erase(word);
                }
            }
            for (size_t start = i; start < total - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++cache[word] == 0) {
                        cache.erase(word);
                    }
                    word = s.substr(start - n, n);
                    if (--cache[word] == 0) {
                        cache.erase(word);
                    }
                }
                if (cache.empty()) {
                    retval.emplace_back(start);
                }
            }
        }

        return retval;
    }
};

int main()
{
    Solution s;

    string str = "barfoothefoobarman";
    vector<string> words{"bar", "foo"};
    cout << "Input: s = \"" << str << "\", words = ";
    print_array(words);
    cout << endl;

    vector<int> retval = s.findSubstring(str, words);

    cout << "Output: ";
    print_array(retval);
    cout << endl;

    return 0;
}
