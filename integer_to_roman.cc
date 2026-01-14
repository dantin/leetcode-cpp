#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbol[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                       "XL", "X",  "IX", "V",  "IV", "I"};

    string retval;
    const size_t n = sizeof(radix) / sizeof(radix[0]);
    for (size_t i = 0; i < n && num > 0; i++) {
      int c = num / radix[i];
      num %= radix[i];
      while (c > 0) {
        retval += symbol[i];
        c--;
      }
    }

    return retval;
  }
};

int main() {
  Solution s;

  int i = 3;

  cout << "Input: " << i << endl;

  string retval = s.intToRoman(i);

  cout << "Output: " << retval << endl;

  return 0;
}
