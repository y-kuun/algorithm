/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 这里的问题，暴露了对于计算偏移量的弱势


#include <iostream>
#include <cstddef>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& posorder){
            TreeNode* head = nullptr;
            build(head, posorder.begin(), posorder.end(), inorder.begin(), inorder.end());
            return head;
        }
        template<typename InputIterator>
        void build(TreeNode* &p, InputIterator  pl, InputIterator pr, InputIterator il, InputIterator ir);
};

template<typename InputIterator>
void Solution::build(TreeNode* &p, InputIterator pl, InputIterator pr, InputIterator il, InputIterator ir ){
    if(pl == pr || il == ir)
        return ;
    InputIterator pit = pl;
    while(pit+1 != pr)
        pit++;
    cout<<*((pr-1))<<endl;;
    p = new TreeNode(*(pit));
    auto it = find(il, ir, *(pit));
    auto tree_size = distance(il, it);

    build(p->left, pl, next(pl, tree_size), il, next(il, tree_size));
    build(p->right,next(pl, tree_size), prev(pr), next(it), ir);
}

int main(){
    vector<int> p{ 2, 1 ,3};
    vector<int> i{2,3,1};
    TreeNode *head;
    Solution s;
    head = s.buildTree(p,i);
    return 0;
}
