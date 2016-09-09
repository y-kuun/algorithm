#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL)
                return;
            stack<TreeLinkNode*> st;
            queue<TreeLinkNode*> qt;
            TreeLinkNode* pc;
            TreeLinkNode* pp;
            size_t left_range, right_range;
            size_t depth = 1;
            qt.push(root);
            while(!qt.empty()){
                left_range = 1 << (depth - 1);
                right_range = (1 << depth) - 1;
                depth++;
                for(int i = left_range; i <= right_range; i++){
                    pc = qt.front();
                    if( pc->left != NULL && pc->right != NULL){
                        qt.push(pc->left);
                        qt.push(pc->right);
                    }
                    qt.pop();
                    st.push(pc);
                }
                for(int i = left_range; i<= right_range; i++){
                    if( i == left_range){
                        pp = st.top();
                    }
                    else {
                        pc = st.top();
                        pc->next = pp;
                        pp = pc;
                    }
                    st.pop();
                }
            }
        }
};
