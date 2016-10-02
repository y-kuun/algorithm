/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    void reorderList(ListNode* head) {
        auto p = head;
        int len = 0;
        ListNode assist_arr(0);
        auto ap = &assist_arr;

        // 计算长度
        while (NULL != p) {
            p = p->next;
            len++;
        }
        if (len <= 1) return;
        int n = (len - 1) / 2;

        p = head;
        while (n--) {
            p = p->next;
        }
        while (p->next != NULL) {
            auto tmp = p->next;
            p->next = tmp->next;
            tmp->next = NULL;
            ap->next = tmp;
            ap = tmp;
        }

        // 逆序 assist_arr;
        ap = &assist_arr;
        p = ap->next;
        ap->next = NULL;
        while (p != NULL) {
            auto tmp = p;
            p = p->next;
            tmp->next = ap->next;
            ap->next = tmp;
        }
        ap = ap->next;
        p = head;
        // 插回去
        while (ap != NULL) {
            auto tmp = ap;
            ap = ap->next;
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
    }
};