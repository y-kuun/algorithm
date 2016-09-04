/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int left_dep;
        int right_dep;
        left_dep = helper(root->left) + 1;
        right_dep = helper(root->right) + 1;
        int n = left_dep - right_dep;
        if (left_dep == 0 || right_dep == 0) {
            return -1;
        }
        if (n > 1 || n < -1) {
            return -1;
        }
        return left_dep > right_dep ? left_dep : right_dep;
    }
    bool isBalanced(TreeNode* root) {
        if (helper(root) == -1) {
            return false;
        } else
            return true;
    }
};