/**
 * Definition for singly-linked list.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        auto prev = head;
        auto next = prev->next;
        while (next != NULL) {
            if (prev->val == next->val) {
                prev->next = next->next;
                delete next;
                next = prev->next;
            } else {
                prev = next;
                next = prev->next;
            }
        }
        return head;
    }
};