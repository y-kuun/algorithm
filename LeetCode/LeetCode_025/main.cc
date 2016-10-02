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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto chead = dummy;
        auto p = chead->next;
        int cnt = 0;
        while (p != NULL) {
            p = p->next;
            cnt++;
        }
        // 计算长度如果够长那么进行计算
        cnt = cnt / k;
        if (cnt == 0) return head;
        auto rear = chead;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < k; j++) {
                if (chead == rear) {
                    rear = rear->next;
                } else {
                    auto tmp = rear->next;
                    rear->next = tmp->next;

                    tmp->next = chead->next;
                    chead->next = tmp;
                }
            }
            chead = rear;
        }
        auto tmp = dummy;
        dummy = dummy->next;
        delete tmp;
        return dummy;
    }
};