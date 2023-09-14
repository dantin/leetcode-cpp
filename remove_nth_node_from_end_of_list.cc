#include <iostream>

#include "singly_linked_list.h"

using namespace std;

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy;
        dummy.next = head;

        int len = 0;
        ListNode *first = head;
        while (first != nullptr) {
            len++;
            first = first->next;
        }

        len = len - n;
        first = &dummy;
        while (len > 0) {
            len--;
            first = first->next;
        }

        first->next = first->next->next;
        //delete first;

        return dummy.next;
    }
};

int main()
{
    Solution s;
    ListNode *list = build_by_num(54321);
    int n = 2;
    cout << "Input: ";
    print_list(list);
    cout << ", n = " << n << endl;

    ListNode *retval = s.removeNthFromEnd(list, n);

    cout << "Output: ";
    print_list(retval);
    cout << endl;

    return 0;
}
