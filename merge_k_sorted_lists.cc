#include <iostream>
#include <vector>

#include "singly_linked_list.h"

using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        size_t n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (size_t i = 0; i < n / 2; i++) {
                lists[i] = merge2List(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

private:
    ListNode *merge2List(ListNode *n1, ListNode *n2) {
        ListNode dummy(0);
        ListNode *p = &dummy;

        while (n1 && n2) {
            if (n1->val < n2->val) {
                p->next = n1;
                n1 = n1->next;
            } else {
                p->next = n2;
                n2 = n2->next;
            }
            p = p->next;
        }
        if (n1) {
            p->next = n1;
        }
        if (n2) {
            p->next = n2;
        }
        return dummy.next;
    }
};

int main()
{
    ListNode *n1 = build_by_num(541);
    ListNode *n2 = build_by_num(431);
    ListNode *n3 = build_by_num(62);

    vector<ListNode *> lists{n1, n2, n3};

    cout << "Input:" << endl;
    cout << "[" << endl;
    for (auto it = lists.begin(); it != lists.end(); ++it) {
        cout << "  ";
        print_list(*it);
        if ((it + 1) != lists.end()) {
            cout << ", " << endl;
        }
    }
    cout << endl << "]" << endl;

    Solution s;
    ListNode *retval = s.mergeKLists(lists);

    cout << "Output: ";
    print_list(retval);
    cout << endl;

    return 0;
}
