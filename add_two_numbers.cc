#include <iostream>
#include <utility>
#include <vector>

#include "singly_linked_list.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode *tail = &dummy;

        int s = 0;
        while( l1 || l2 ) {
            int n = s + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            s = n / 10;
            n = n % 10;
            tail->next = new ListNode(n);
            tail = tail->next;
            if ( l1 ) {
                l1 = l1->next;
            }
            if ( l2 ) {
                l2 = l2->next;
            }
        }

        while (s != 0) {
            int n = s % 10;
            s = s / 10;
            tail->next = new ListNode(n);
            tail = tail->next;
        }

        return dummy.next;
    }
};

int main()
{
    vector<pair<vector<int>, vector<int>>> cases{
        {{2, 4, 3}, {5, 6, 4}},
        {{0}, {0}},
        {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}},
    };
    Solution s;

    for (auto c : cases) {
        ListNode *l1 = build_by_values(c.first);
        cout << "Input: l1 = ";
        print_list(l1);
        ListNode *l2 = build_by_values(c.second);
        cout << ", l2 = ";
        print_list(l2);
        cout << endl;

        ListNode *retval = s.addTwoNumbers(l1, l2);

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
