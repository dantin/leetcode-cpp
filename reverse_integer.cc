#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long temp = x;
        bool sign;
        if (x < 0) {
            sign = false;
            temp = -temp;
        } else {
            sign = true;
        }

        long long retval = 0;
        while (temp != 0) {
            int n = temp % 10;
            retval += n;
            temp /= 10;
            if (temp == 0) {
                break;
            }
            retval *= 10;
        }
        if(retval > 2147483647 || (!sign && retval> 2147483648)) {
            return 0;
        }
        if (sign) {
            return retval;
        } else {
            return -retval;
        }
    }
};

int main()
{
    int n = 123;
    Solution s;

    cout << "Input: " << n << endl;

    int x = s.reverse(n);

    cout << "Ouput: " << x << endl;

    return 0;
}
