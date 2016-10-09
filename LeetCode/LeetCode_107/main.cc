/**
 * Definition for a binary tree node.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    void walker(vector<vector<int>> &ans, int depth, TreeNode *p) {
        if (p == nullptr) return;
        if (depth >= ans.size()) {
            cout << "here!" << p->val << endl;
            ans.push_back(vector<int>{p->val});
        } else {
            cout << "there" << p->val << endl;
            ans[depth].push_back(p->val);
        }
        walker(ans, depth + 1, p->left);
        walker(ans, depth + 1, p->right);
    }

   public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        walker(ans, 0, root);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};