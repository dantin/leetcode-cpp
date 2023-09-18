#include <iostream>

#include "singly_linked_list.h"

using namespace std;

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy;
        dummy.next = head;

        ListNode *curr = head;
        ListNode *prev = &dummy;
        ListNode *tmp;

        while (curr && curr->next) {
            tmp = curr->next->next;
            curr->next->next = curr;
            prev->next = curr->next;
            curr->next = tmp;
            prev = curr;
            curr = curr->next;
        }

        return dummy.next;
    }
};

int main()
{
    Solution s;

    ListNode *list = build_by_num(4321);
    cout << "Input: ";
    print_list(list);
    cout << endl;

    ListNode *retval = s.swapPairs(list);

    cout << "Output: ";
    print_list(retval);
    cout << endl;

    return 0;
}
