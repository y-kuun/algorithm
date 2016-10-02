/**
 * Definition for singly-linked list with a random pointer.
 */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
   public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        auto p = head;
        if (head == NULL) return head;
        while (p != NULL) {
            auto tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        p = head;

        while (p != NULL) {
            if (p->random != NULL)
                p->next->random = p->random->next;
            else
                p->next->random = NULL;
            p = p->next->next;
        }
        RandomListNode res(0);
        auto rear = &res;
        p = head;
        while (p != NULL) {
            auto tmp = p->next;
            p->next = tmp->next;
            p = p->next;
            // 下一跳
            rear->next = tmp;
            tmp->next = NULL;
            rear = tmp;
        }
        return res.next;
    }
};