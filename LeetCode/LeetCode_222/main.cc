#include <iostream>
#include <queue>
#include <bitset>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        //void setbs(bitset<10000> &bs,size_t num, size_t depth);
        size_t treeDepth(TreeNode* pnode){
            if(pnode == NULL)
                return 0;
            return 1 + treeDepth(pnode->left);
        }
        bool btsearch(TreeNode* pnode, size_t depth, size_t num){
            unsigned int base = 0x1;
            for(int i = depth - 2; i >= 0; i-- ){
                if(((base << i) & num) != 0){
                    pnode = pnode->right;
                }else{
                    pnode = pnode->left;
                }
            }
            if(pnode == NULL)
                return false;
            else return true;
        }
        int countNodes(TreeNode* root) {
            if(root == NULL)
                return size_t(0);
            size_t ans(0);
            size_t depth = treeDepth(root);
            size_t left_range = 1 << (depth - 1);
            size_t right_range = (1 << depth) - 1;
            TreeNode* tmp;
            // bit[1] = 0 go to the left 50%, bit[1] = 1 go to the right 50%
            // depth = n
            // so
            size_t mid;
            bool flag;
            while(left_range <= right_range){
                mid = (left_range + right_range)/2;
                if(btsearch(root, depth, mid) == false){
                    // left
                    right_range = mid - 1;
                    if(right_range == left_range)
                        flag == false;
                } else {
                    // right
                    left_range = mid + 1;
                    if(right_range == left_range)
                        flag == true;
                }
            }
            if(flag)
                return left_range;
            else return left_range - 1;

        }
};

