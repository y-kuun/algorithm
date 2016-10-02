/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//  指针的操作需要小心

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        auto start_head = tmp;
        auto p = start_head;
        while (p->next != NULL) {
            if (p->next->val < x && p != start_head) {
                auto cp = p->next;
                auto next = cp->next;
                p->next = next;
                cp->next = start_head->next;
                start_head->next = cp;

                // 当前状态向前推进
                start_head = cp;
            } else if (p->next->val < x && p == start_head) {
                p = p->next;
                start_head = start_head->next;
            } else
                p = p->next;
        }
        start_head = tmp->next;
        delete tmp;
        return start_head;
    }
};