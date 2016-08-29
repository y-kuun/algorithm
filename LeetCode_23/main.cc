#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// TLE

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


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
            for(auto it = tmp_lists->begin(); it != tmp_lists->end();){
                if(NULL == (*it)){
                    cnt++;
                    tmp_lists->erase(it);
                    continue;
                }
                if((*it)->val < min_val){
                    min_pos = distance(tmp_lists->begin(), it);
                    min_val = (*it)->val;
                }
                it++;
            }
            if(cnt == tmp_lists->size()){
                delete tmp_lists;
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
    }
};

