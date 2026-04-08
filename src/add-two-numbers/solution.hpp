#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy;
        ListNode* tail = &dummy;

        int carry = 0;
        while (l1 || l2) {
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;
            int digit = sum % 10;
            tail->next = new ListNode(digit);
            tail = tail->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        if (carry != 0) {
            tail->next = new ListNode(carry);
        }

        return dummy.next;
    }
};

ListNode* build_by_values(std::vector<int> values)
{
    ListNode dummy;
    ListNode* tail = &dummy;

    for (auto it = values.begin(); it != values.end(); ++it) {
        tail->next = new ListNode(*it);
        tail = tail->next;
    }

    return dummy.next;
}

void print_list(ListNode* head)
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
