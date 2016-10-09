
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.

using namespace std;

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> st;
        auto p = root;
        if (p != NULL) st.push(p);

        while (!st.empty()) {
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            if (NULL != p->right) {
                st.push(p->right);
            }
            if (NULL != p->left) {
                st.push(p->left);
            }
        }

        return ans;
    }
};
 */

template <unsigned int t>
struct fabi {
    enum { sum = fabi<t - 1>::sum + fabi<t - 2>::sum };
};

template <>
struct fabi<1> {
    enum { sum = 1 };
};

template <>
struct fabi<2> {
    enum { sum = 2 };
};

int main(int argc, char **argcv) {
    fabi<10> ans;
    cout << ans.sum << endl;
    return 0;
}