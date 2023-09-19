#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long m = abs((long long) dividend);
        long long n = abs((long long) divisor);
        long long retval = 0;
        if (m < n) {
            return 0;
        }

        while (m >= n) {
            long long t = n, p = 1;
            while (m > (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            retval += p;
            m -= t;
        }

        if ((dividend < 0) ^ (divisor < 0)) {
            retval = -retval;
        }
        return retval > INT_MAX ? INT_MAX : retval;
    }
};

int main()
{
    Solution s;

    int dividend = 10, divisor = 3;
    cout << "Input: dividend = " << dividend << ", divisor = " << divisor << endl;

    int retval = s.divide(dividend, divisor);

    cout << "Output: " << retval << endl;

    return 0;
}
