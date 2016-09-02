#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;

        int len = 0;
        ListNode hnode(0);

        ListNode* p = head;
        hnode.next = head;
        while (NULL != p) {
            len++;
            p = p->next;
        }

        ListNode* r = head;
        k = k % len;
        int tmp = len - k;
        if (tmp == len) return head;
        while (--tmp) {
            r = r->next;
        }

        ListNode* phead = &hnode;
        ListNode* prear = r->next;

        tmp = k;
        while (k--) {
            r->next = prear->next;
            prear->next = phead->next;
            phead->next = prear;

            phead = phead->next;
            prear = r->next;
        }
        return hnode.next;
    }
};