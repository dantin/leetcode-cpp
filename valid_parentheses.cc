#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> cache;
        for (auto c : s) {
            if (left.find(c) != string::npos) {
                cache.push(c);
            } else {
                if (cache.empty() || cache.top() != left[right.find(c)]) {
                    return false;
                } else {
                    cache.pop();
                }
            }
        }
        return cache.empty();
    }
};

int main()
{
    Solution s;

    string str = "()";
    cout << "Input: " << str << endl;

    bool x = s.isValid(str);

    cout << "Output: " << (x ? "true" : "false") << endl;

    return 0;
}
