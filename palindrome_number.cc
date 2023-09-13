#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int d = 1;
        while (x / d >= 10) {
            d *= 10;
        }

        while (x > 0) {
            int q = x / d;
            int r = x % 10;
            if (q != r) {
                return false;
            }
            // x <- x % (d / 10)
            x = x % d / 10;
            d /= 100;
        }

        return true;
    }
};

int main()
{
    Solution s;

    int n = 121;
    cout << "Input: " << n << endl;

    bool retval = s.isPalindrome(n);

    cout << "Output: " << (retval ? "true" : "false") << endl;

    return 0;
}
