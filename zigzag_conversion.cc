#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    string retval;
    size_t n = s.size();
    size_t cycleLen = 2 * static_cast<size_t>(numRows) - 2;

    for (int i = 0; i < numRows; i++) {
      for (size_t j = 0; j + static_cast<size_t>(i) < n; j += cycleLen) {
        retval += s[j + static_cast<size_t>(i)];
        // For middle rows, add the diagonal character
        if (i != 0 && i != numRows - 1) {
          size_t diagonalIdx = j + cycleLen - static_cast<size_t>(i);
          if (diagonalIdx < n) {
            retval += s[diagonalIdx];
          }
        }
      }
    }
    return retval;
  }
};

int main() {
  string str = "PAYPALISHIRING";
  int numRows = 3;
  cout << "Input: s = " << str << ", numRows = " << numRows << endl;

  Solution s;
  string retval = s.convert(str, numRows);

  cout << "Output: " << retval << endl;

  return 0;
}
