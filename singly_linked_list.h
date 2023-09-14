#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *build_by_num(int n)
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

void print_list(ListNode *head)
{
    std::cout << "[";
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) {
            std::cout << ", ";
        }
        head = head->next;
    }
    std::cout << "]";
}

#endif
