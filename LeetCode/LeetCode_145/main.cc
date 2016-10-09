#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* p = root;
        do {
            while (NULL != p) {
                st.push(p);
                p = p->left;
            }
            TreeNode* q = NULL;
            while (!st.empty()) {
                p = st.top();
                st.pop();
                if (p->right == q) {
                    ans.push_back(p->val);
                    q = p;
                    p = NULL;
                } else {
                    st.push(p);
                    p = p->right;
                    break;
                }
            }
        } while (!st.empty());
        return ans;
    }
};

int main(int argc, char** argv) { return 0; }