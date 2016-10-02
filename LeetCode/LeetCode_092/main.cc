/**
 * Definition for singly-linked list.
 */

#include <iostream>
using namespace std;

// 需要处理好边界条件

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int len = n - m + 1;
        if (len == 1) {
            return head;
        }
        ListNode* start_head;
        ListNode* tmp;
        if (m == 1) {
            tmp = new ListNode(0);
            tmp->next = head;
            start_head = tmp;
        } else {
            start_head = head;
        }

        for (int i = 0; start_head != NULL && i < m - 2; i++) {
            start_head = start_head->next;
        }
        if (start_head == NULL) {
            return head;
        }
        auto rear = start_head->next;
        if (NULL == rear) {
            return head;
        }
        for (int i = 1; i < len; i++) {
            auto tmp = rear->next;
            if (tmp == NULL) {
                return head;
            }
            rear->next = tmp->next;
            tmp->next = start_head->next;
            start_head->next = tmp;
        }
        if (m == 1) {
            start_head = start_head->next;
            delete tmp;
            return start_head;
        }
        return head;
    }
};