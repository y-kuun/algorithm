/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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

class Solution1 {
   public:
    int recursion(TreeNode *p, int flag) {
        if (NULL == p) {
            return 0;
        }
        int res_0;
        int res_1;

        res_0 = recursion(p->right, 0) + recursion(p->left, 0);
        if (flag == 0) {
            res_1 = p->val + recursion(p->right, 1) + recursion(p->left, 1);
        } else
            res_1 = -1;

        if (res_0 > res_1) {
            return res_0;
        } else
            return res_1;
    }
    int rob(TreeNode *root) { return recursion(root, 0); }
};

class Solution {
   public:
    int max(int a, int b) { return a > b ? a : b; }
    int rob(TreeNode *root) {
        if (root == NULL) return 0;
        int fanum = 0;
        int chnum = 0;
        int depth = 1;

        queue<TreeNode *> bfs;
        vector<int> dp_rub(2, 0);
        vector<int> dp_not_rub(2, 0);

        bfs.push(root);

        fanum = 1;

        while (!bfs.empty()) {
            TreeNode *p = bfs.front();
            bfs.pop();
            fanum--;

            dp_rub[depth] += dp_not_rub[depth - 1] + p->val;
            dp_not_rub[depth] += max(dp_not_rub[depth - 1], dp_rub[depth - 1]);

            if (p->right != NULL) {
                bfs.push(p->right);
                chnum++;
            }

            if (p->left != NULL) {
                bfs.push(p->left);
                chnum++;
            }

            if (fanum == 0) {
                fanum = chnum;
                chnum = 0;
                dp_rub.push_back(0);
                dp_not_rub.push_back(0);
                depth++;
            }
        }

        return max(dp_rub[depth - 1], dp_not_rub[depth - 1]);
    }
};