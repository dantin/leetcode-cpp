#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *build_by_num(int n)
{
    ListNode dummy;
    ListNode *p = &dummy;

    while (n != 0) {
        int val = n % 10;
        n /=  10;
        p-> next = new ListNode(val);
        p = p->next;
    }
    return dummy.next;
}

ListNode *build_by_values(std::vector<int> values)
{
    ListNode dummy;
    ListNode *tail = &dummy;

    for (auto it = values.begin(); it != values.end(); ++it) {
        tail -> next = new ListNode(*it);
        tail = tail->next;
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

void clean_list(ListNode *head)
{
    while (head != nullptr) {
        ListNode *node = head->next;
        delete head;
        head =node;
    }
}

#endif
