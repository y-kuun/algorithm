#include <iostream>
#include <queue>
#include <iterator>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// plan A , inorder search than check

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirrored(root);
    }
    bool isMirrored(TreeNode* root);
};

bool Solution::isMirrored(TreeNode* root){
    if(NULL == root)
        return true;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while(!q.empty()){
        TreeNode* lft = q.front();
        q.pop();
        TreeNode* rht = q.front();
        q.pop();
        if(lft != NULL && rht != NULL){
            if(lft->val == rht->val){
                q.push(lft->left);
                q.push(rht->right);
                q.push(lft->right);
                q.push(rht->left);
            } else return false;
        } else if( lft == NULL && rht == NULL)
    }
    return true;
}
