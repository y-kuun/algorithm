/**
 * Definition for a binary tree node.
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *p = root;

        while (p != NULL || !st.empty()) {
            if (p != NULL) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                ans.push_back(p->val);
                st.pop();
                p = p->right;
            }
        }
        return ans;
    }
};