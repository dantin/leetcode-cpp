#ifndef SOLUTION_HPP
#define SOLUTION_HPP

class Solution {
   public:
    int reverse(int x)
    {
        int retval = 0;
        const int MAX_DIV_10 = 214748364;   // INT_MAX / 10
        const int MIN_DIV_10 = -214748364;  // INT_MIN / 10

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check for overflow before multiplying by 10 and adding pop
            // Maximum value of INT_MAX is 2147483647
            if (retval > MAX_DIV_10 || (retval == MAX_DIV_10 && pop > 7)) {
                return 0;
            }
            // Minimum value of INT_MIN is -2147483648
            if (retval < MIN_DIV_10 || (retval == MIN_DIV_10 && pop < -8)) {
                return 0;
            }

            retval = retval * 10 + pop;
        }

        return retval;
    }
};

#endif
