#ifndef SOLUTION_HPP
#define SOLUTION_HPP

class Solution {
   public:
    bool isPalindrome(int x)
    {
        // Negative numbers and numbers ending in 0 (except 0 itself) cannot be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by reversedHalf/10
        // For example when the input is 12321, at the end of the while loop we get x = 12,
        // reversedHalf = 123, since the middle digit doesn't matter in palidrome(it will always
        // equal to itself), we can simply get rid of it.
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

#endif
