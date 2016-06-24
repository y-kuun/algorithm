#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//  使用字典树进行处理
typedef struct dicnode{
    vector<int> ans;
    vector<int> path;
    struct dicnode* child[26];
    dicnode(){
        ans.clear();
        ans.shrink_to_fit();
        path.clear();
        path.shrink_to_fit();
        memset(child, 0, sizeof(child));
    }
}dicTree;


class Solution {
    public:
        bool isPali(int first, int last, const string &target);
        vector<vector<int>> palindromePairs(vector<string>& words) {
            dicTree root;
            vector<vector<int>> ans;
            vector<int> tmp;
            dicTree *p;
            // 将所有的字符串作为左半部进行插入
            // insert all the lhs string into the dictionary tree
            for(int i = 0; i < words.size(); i++){
                p = &root;
                for(int k = 0; k < words[i].size(); k++){
                    // 将经过的字符串的序号记入
                    if(p->child[words[i][k] - 'a'] == NULL)
                        p->child[words[i][k] - 'a'] = new dicnode;
                    p = p->child[words[i][k] - 'a'];
                }
                // if the string ends write the # into the answer vector
                p->ans.push_back(i);
                p->ans.shrink_to_fit();
            }
            for(int i = 0; i < words.size(); i++){
                p = &root;
                for(int k = 0; k < words[i].size(); k++){
                    if(p->ans.size() > 0){
                        if(find(p->ans.begin(),p->ans.end(), i) == p->ans.end())
                            p->path.push_back(i);
                    }
                    p = p->child[words[i][k] - 'a'];
                }
                if(p->ans.size() > 0){
                    if(find(p->ans.begin(),p->ans.end(), i) == p->ans.end())
                        p->path.push_back(i);
                }
                // if the string ends write the # into the answer vector
            }
            // 将所有的字符串作为右半部进行匹配
            // 如果一方字符串结束需要对剩余字符串进行验证
            for(int i = 0; i < words.size(); i++){
                p = &root;
                if(p->ans.size() > 0){
                    // 处理lhs短，rhs长
                    // 一个lhs 结束，可能从存在共同前缀的lhs字符串？
                    // 但是 rhs 未结束
                    // 0  ~ k - 1
                    // 需要判断是否存在更长的串
                    if(isPali(0, words[i].size() - 1 , words[i])){
                        auto it = p->ans.begin();
                        while(it != p->ans.end()){
                            if( *it == i){
                                it++;
                                continue;
                            }
                            tmp.clear();
                            tmp.push_back(*it);
                            tmp.push_back(i);
                            ans.push_back(tmp);
                            it++;
                        }
                    }
                }
                // for the rhs, we go by reverse direction
                for(int k = words[i].size() - 1; k >= 0; k--){
                    // 继续前进
                    p = p->child[words[i][k] - 'a'];
                    // 后续没有接words[i][k]
                    if(p == NULL){
                        // pattern string not found
                        break;
                    }
                    if(p->ans.size() > 0){
                        // 处理lhs短，rhs长
                        // 一个lhs 结束，可能从存在共同前缀的lhs字符串？
                        // 但是 rhs 未结束
                        // 0  ~ k - 1
                        // 需要判断是否存在更长的串
                        if(isPali(0, k-1, words[i])){
                            auto it = p->ans.begin();
                            while(it != p->ans.end()){
                                if( *it == i){
                                    it++;
                                    continue;
                                }
                                tmp.clear();
                                tmp.push_back(*it);
                                tmp.push_back(i);
                                ans.push_back(tmp);
                                it++;
                            }
                        }
                    }
                } // end for of the reverse string
                // rhs 结束了， lhs结束了
                if( p == NULL)
                    continue;
                // rhs 结束然而 lhs未结束
                // rhs 短 lhs 长
                auto it = p->path.begin();
                int length = words[i].size();
                while(it != p->path.end()){
                    if(isPali( words[i].size(), words[*it].size() - 1, words[*it])){
                        tmp.clear();
                        tmp.push_back(*it);
                        tmp.push_back(i);
                        ans.push_back(tmp);
                    }
                    it++;
                }
            }
            return ans;
        }
};

bool Solution::isPali(int first, int last, const string &target){
    while(first < last){
        if(target[first] != target[last])
            return false;
        first++;
        last--;
    }
    return true;
}

int main(){
    Solution s;
    //auto ans = s.palindromePairs(words);
}
