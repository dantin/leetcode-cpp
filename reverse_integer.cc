#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    long long retval = 0;
    const int INT_MAX_VAL = 2147483647;
    const long long INT_MIN_ABS = 2147483648LL;

    while (x != 0) {
      retval = retval * 10 + x % 10;
      x /= 10;
    }

    // Check for overflow: positive numbers must be <= INT_MAX
    // negative numbers (when reversed) must have abs <= INT_MIN_ABS
    if (retval > INT_MAX_VAL || retval < -INT_MIN_ABS) {
      return 0;
    }

    return static_cast<int>(retval);
  }
};

int main() {
  int n = 123;
  Solution s;

  cout << "Input: " << n << endl;

  int x = s.reverse(n);

  cout << "Output: " << x << endl;

  return 0;
}
