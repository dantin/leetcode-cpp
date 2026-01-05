#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    map<char, size_t> char_index;
    size_t left = 0;

    for (size_t right = 0; right < s.size(); right++) {
      char c = s[right];
      // If character is already in the window, move left pointer
      // to the position right after the last occurrence of this character
      if (char_index.find(c) != char_index.end() && char_index[c] >= left) {
        left = char_index[c] + 1;
      }
      char_index[c] = right;
      max_length = max(max_length, static_cast<int>(right - left + 1));
    }

    return max_length;
  }
};

int main() {
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
