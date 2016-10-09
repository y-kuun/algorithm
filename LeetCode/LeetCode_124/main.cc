#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int walker(TreeNode *p) {
        if (p == NULL) return 0;
        // left side consisdered
        int left = walker(p->left);
        // right side considered
        int right = walker(p->right);
        // both sided considered
        // for situation should take into consideration
        int both = max(p->val, left + right + p->val);
        both = max(both, left + p->val);
        both = max(both, right + p->val);
        if (both > this->max) {
            this->max = both;
        }

        // only one single path returned
        left = max(p->val, left + p->val);
        // only right
        right = max(both, right + p->val);
        return right;
        // both
    }
    int max;

   public:
    int maxPathSum(TreeNode *root) {
        this->max = 0;
        walker(root);
        return this->max;
    }
};