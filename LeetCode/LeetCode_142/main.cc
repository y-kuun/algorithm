/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        auto prev = head;
        auto rear = head;
        while (prev != NULL && prev->next != NULL) {
            prev = prev->next->next;
            rear = rear->next;
            if (prev == rear) {
                return true;
            }
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if (!hasCycle(head)) return NULL;
        auto prev = head;
        auto rear = head;
        while (prev != NULL && prev->next != NULL) {
            prev = prev->next->next;
            rear = rear->next;
            if (prev == rear) {
                break;
            }
        }
        rear = head;
        while (rear != prev) {
            rear = rear->next;
            prev = prev->next;
        }
        return rear;
    }
};