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
    void walker(TreeNode* root, int num) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            this->sum += num * 10 + root - val;
        }
        walker(root->left, num * 10 + root->val);
        walker(root->right, num * 10 + root->val);
    }
    int sum;

   public:
    int sumNumbers(TreeNode* root) {
        this->sum = 0;
        walker(root, 0);
        return this->sum;
    }
};