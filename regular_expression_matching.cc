#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) { return isMatch(s.c_str(), p.c_str()); }

 private:
  bool isMatch(const char *s, const char *p) {
    if (*p == '\0') {
      // if pattern is empty, then string must also be empty
      return *s == '\0';
    }
    if (*(p + 1) != '*') {
      // if next character is not '*', then check if current character matches
      if (*s != '\0' && (*p == *s || *p == '.')) {
        return isMatch(s + 1, p + 1);
      } else {
        // if current character does not match, then return false
        return false;
      }
    } else {
      // if next character is '*', then check if current character matches
      while (*p == *s || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p + 2)) {
          return true;
        }
        s++;
      }
      return isMatch(s, p + 2);
    }
  }
};

int main() {
  Solution s;

  string str = "aa";
  string p = "a";
  cout << "Input: s = " << str << ", p = " << p << endl;

  bool retval = s.isMatch(str, p);

  cout << "Output: " << (retval ? "true" : "false") << endl;

  return 0;
}
