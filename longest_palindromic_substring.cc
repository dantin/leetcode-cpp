#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    size_t n = s.size();
    if (n == 0) {
      return "";
    }

    // Allocate dp and init.
    // dp[i][j] is true if the substring from index i to j is a palindrome.
    bool **dp = new bool *[n];
    for (size_t i = 0; i < n; i++) {
      dp[i] = new bool[n];
    }
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        dp[i][j] = false;
      }
    }

    // Build dp table.
    // Fill by increasing substring length to ensure dp[j+1][i-1] is computed
    // first
    size_t maxLen = 1;
    size_t start = 0;

    // Initialize: single characters are palindromes
    for (size_t i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    // Fill for length 2
    for (size_t i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        if (maxLen < 2) {
          maxLen = 2;
          start = i;
        }
      }
    }

    // Fill for length 3 and above
    for (size_t len = 3; len <= n; len++) {
      for (size_t i = 0; i <= n - len; i++) {
        size_t j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          if (len > maxLen) {
            maxLen = len;
            start = i;
          }
        }
      }
    }

    // free memory.
    for (size_t i = 0; i < n; i++) {
      delete[] dp[i];
    }
    delete[] dp;

    return s.substr(start, maxLen);
  }
};

int main() {
  string str = "babad";
  cout << "Input: " << str << endl;

  Solution s;
  string retval = s.longestPalindrome(str);

  cout << "Output: " << retval << endl;

  return 0;
}
