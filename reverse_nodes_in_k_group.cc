#include <iostream>

#include "singly_linked_list.h"

using namespace std;

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1 || !head) {
            return head;
        }

        ListNode dummy;
        dummy.next = head;

        ListNode *prev;
        ListNode *curr = &dummy;
        while (curr) {
            prev = curr;
            for (int i = 0; i < k; i++) {
                curr = curr->next;
                if (!curr) {
                    return dummy.next;
                }
            }
            curr = reverse(prev, curr->next);
        }

        return dummy.next;
    }

private:
    ListNode *reverse(ListNode *prev, ListNode *end) {
        ListNode *curr = prev->next;
        while (curr->next != end) {
            ListNode *n = curr->next;
            curr->next = n->next;
            n->next = prev->next;
            prev->next = n;
        }
        return curr;
    }
};

int main()
{
    ListNode *list = build_by_num(54321);
    int k = 2;

    cout << "Input: ";
    print_list(list);
    cout << ", k = " << k << endl;

    Solution s;
    ListNode *retval = s.reverseKGroup(list, k);

    cout << "Output: ";
    print_list(retval);
    cout << endl;

    return 0;
}
