#include <iostream>

#include "solution.hpp"

using namespace std;

int main()
{
    int n = 123;
    Solution s;

    cout << "Input: " << n << endl;

    int x = s.reverse(n);

    cout << "Output: " << x << endl;

    return 0;
}
