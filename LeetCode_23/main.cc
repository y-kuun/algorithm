#include <vector>
#include <iostream>
#include <climits>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        ListNode* cur = NULL;
        vector<ListNode*> *tmp_lists = new vector<ListNode*>(lists);

        while(true){
            int min_val = INT_MAX;
            int min_pos = -1;
            int cnt = 0;
            for(auto it = tmp_lists->begin(); it != tmp_lists->end(); it++){
                if(NULL == (*it)){
                    cnt++;
                    continue;
                }
                if((*it)->val < min_val){
                    min_pos = distance(it, tmp_lists->begin());
                    min_val = (*it)->val;
                }
            }
            if(cnt == tmp_lists->size()){
                return res;
            }
            if( res == NULL){
                    res = cur = (*tmp_lists)[min_pos];
                    (*tmp_lists)[min_pos] = (*tmp_lists)[min_pos]->next;
            }else {
                    cur->next = (*tmp_lists)[min_pos];
                    cur = cur->next;
                    (*tmp_lists)[min_pos] = (*tmp_lists)[min_pos]->next;
            }
        }
        delete tmp_lists;
    }
};
