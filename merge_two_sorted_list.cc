#include <iostream>

#include "singly_linked_list.h"

using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy;

        ListNode *p = &dummy;
        while (list1 && list2) {
            int val1 = list1->val;
            int val2 = list2->val;
            if (val1 < val2) {
                p->next = list1;
                p = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = list2;
                list2 = list2->next;
            }
        }
        if (list1) {
            p->next = list1;
        }
        if (list2) {
            p->next = list2;
        }

        return dummy.next;
    }
};

int main()
{
    Solution s;

    ListNode *list1 = build_by_num(421);
    ListNode *list2 = build_by_num(431);
    cout << "Input: ";
    print_list(list1);
    cout << ", ";
    print_list(list2);
    cout << endl;

    ListNode *retval = s.mergeTwoLists(list1, list2);

    cout << "Output: ";
    print_list(retval);
    cout << endl;

    return 0;
}
