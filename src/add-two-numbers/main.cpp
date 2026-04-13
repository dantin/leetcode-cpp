#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace std;

int main()
{
    vector<pair<vector<int>, vector<int>>> cases{
        {{2, 4, 3}, {5, 6, 4}},
        {{0}, {0}},
        {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}},
    };
    Solution s;

    for (auto c : cases) {
        ListNode* l1 = build_by_values(c.first);
        cout << "Input: l1 = ";
        print_list(l1);
        ListNode* l2 = build_by_values(c.second);
        cout << ", l2 = ";
        print_list(l2);
        cout << endl;

        ListNode* retval = s.addTwoNumbers(l1, l2);

        cout << "Output: ";
        print_list(retval);
        cout << endl << endl;

        clean_list(l1);
        l1 = nullptr;
        clean_list(l2);
        l2 = nullptr;
        clean_list(retval);
        retval = nullptr;
    }

    return 0;
}