#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *p = &dummy;

        int s = 0;
        while( l1 || l2 ) {
            int val = s + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            s = val / 10;
            val = val % 10;
            p->next = new ListNode(val);
            p = p->next;
            if ( l1 ) {
                l1 = l1->next;
            }
            if ( l2 ) {
                l2 = l2->next;
            }
        }

        while (s != 0) {
            int val = s % 10;
            s = s / 10;
            p->next = new ListNode(val);
            p = p->next;
        }

        return dummy.next;
    }
};

ListNode *build_nums(int n)
{
    ListNode dummy(0);
    ListNode *p = &dummy;

    while (n != 0) {
        int val = n % 10;
        n /=  10;
        p-> next = new ListNode(val);
        p = p->next;
    }
    return dummy.next;
}

void print_nums(ListNode *head)
{
    cout << "[";
    while (head != NULL) {
        cout << head->val;
        if ( head->next != NULL ) {
            cout << ", ";
        }
        head = head->next;
    }
    cout << "]";
}

int main()
{
    ListNode *l1 = build_nums(342);
    cout << "Input: l1 = ";
    print_nums(l1);
    ListNode *l2 = build_nums(465);
    cout << ", l2 = ";
    print_nums(l2);
    cout << endl;

    Solution s;
    ListNode *retval = s.addTwoNumbers(l1, l2);

    cout << "Output: ";
    print_nums(retval);
    cout << endl;

    return 0;
}
