/**
 * Definition for a binary tree node.
 */

#include <algorithm>
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

/**
 * Definition for a binary tree node.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    void walker(vector<pair<int, TreeNode *>> &vec, TreeNode *p) {
        if (nullptr != p) {
            walker(vec, p->left);
            vec.push_back(pair<int, TreeNode *>(p->val, p));
            walker(vec, p->right);
        }
    }
    template <typename RandomIt>
    void print_arr(RandomIt begin, RandomIt end) {
        for (auto it = begin; it != end; it++) {
            cout << it->first << " ";
        }
        cout << endl;
    }

   public:
    //  first build the inorder traveral
    void recoverTree(TreeNode *root) {
        if (root == nullptr) return;
        vector<pair<int, TreeNode *>> vec;
        walker(vec, root);
        auto vec_sorted(vec);
        auto comp = [](pair<int, TreeNode *> a,
                       pair<int, TreeNode *> b) -> bool {
            return a.first < b.first;
        };
        sort(vec_sorted.begin(), vec_sorted.end(), comp);

        print_arr(vec.begin(), vec.end());
        print_arr(vec_sorted.begin(), vec_sorted.end());

        for (int i = 0; i < vec.size(); i++) {
            if (vec_sorted[i].first != vec[i].first) {
                int tmp = vec_sorted[i].second->val;
                vec_sorted[i].second->val = vec[i].second->val;
                vec[i].second->val = tmp;
                break;
            }
        }
    }
};