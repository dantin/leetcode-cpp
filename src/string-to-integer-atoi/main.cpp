#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace std;

int main()
{
    Solution s;

    vector<string> cases = {"42",
                            "   -042",
                            "1337c0d3",
                            "0-1",
                            "words and 987",
                            "-91283472332",
                            "91283472332",
                            "+1",
                            "+-12",
                            "2147483646",
                            "2147483647",
                            "2147483648",
                            "-2147483647",
                            "-2147483648",
                            "-2147483649",
                            "  0000000000012345678",
                            "00000-42a1234"};

    for (const string& str : cases) {
        cout << "Input: \"" << str << "\"" << endl;
        cout << "Output: " << s.myAtoi(str) << "\n" << endl;
    }

    return 0;
}
