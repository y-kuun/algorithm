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
    void recursion(vector<vector<int>>& res, TreeNode* ptn, int depth) {
        if (ptn == NULL) return;
        if (res.size() < depth) {
            res.push_back(vector<int>{ptn->val});
        } else {
            res[depth - 1].push_back(ptn->val);
        }
        recursion(res, ptn->left, depth + 1);
        recursion(res, ptn->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        recursion(res, root, 1);
        return res;
    }
};