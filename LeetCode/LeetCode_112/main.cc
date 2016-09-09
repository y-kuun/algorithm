/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // dfs for the tree, make clean there is negative node in the tree;
 // make clean definition for the leave not, which mean there is no child;
class Solution {
   public:
    bool helper(TreeNode* ptn, int left, bool& flag) {
        if (flag) return true;
        if (ptn == NULL) return false;
        if (left - ptn->val == 0 && ptn->left == NULL && ptn->right == NULL) {
            flag = true;
            return flag;
        }
        return helper(ptn->left, left - ptn->val, flag) ||
               helper(ptn->right, left - ptn->val, flag);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag;
        flag = false;
        if (root == NULL) return false;
        return helper(root, sum, flag);
    }
};