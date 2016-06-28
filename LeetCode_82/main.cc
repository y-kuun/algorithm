#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* del_nodes(ListNode* head);
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ans_head = new ListNode(0);
        ListNode *pp, *pc;
        ListNode *ptmp;
        pp = head;
        pc = ans_head;
        while(true){
            ptmp = del_nodes(pp);
            if(ptmp == NULL){
                pc->next = ptmp;
                break;
            }
            if(ptmp == pp){
                pc->next = pp;
                pc = pc->next;
                pp = pp->next;
            }else{
                pp = ptmp;
            }
        }
        return ans_head->next;
    }
};

ListNode* Solution::del_nodes(ListNode* head){
    if(head == NULL)
        return NULL;
    ListNode *pp, *pc, *pn;
    pp = head;
    pn = head->next;
    while(pn != NULL && pp->val == pn->val){
        pc = pn;
        pn = pn->next;
        delete(pc);
    }
    if(pp->next != pn){
       delete pp;
        return pn;
    }else return pp;
}

int main(){
    ListNode *head;
    head = new ListNode(1);
    ListNode *pp = head;
    pp->next = new ListNode(2);
    pp = pp->next;
    pp->next = new ListNode(2);
    Solution s;
    s.deleteDuplicates(head);
}
