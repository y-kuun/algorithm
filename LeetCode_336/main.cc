#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
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
        vector<vector<int>> palindromePairs(vector<string>& words){
            vector<vector<int>> ans;
            unordered_map<string,int> unmap;
            unmap.clear();
            for(int i = 0; i < words.size(); i++)
                unmap[words[i]] = i;
            for(int i = 0; i < words.size(); i++){
                for(int k = 0; k <= words[i].size(); k++){
                    string str1 = words[i].substr(0,k);
                    string str2 = words[i].substr(k);
                    reverse(str1.begin(), str1.end());
                    reverse(str2.begin(), str2.end());
                    if(isPali(0, str1.size() - 1, str1)){
                        if(unmap.find(str2) != unmap.end()){
                            if(i != unmap[str2] && find(ans.begin(), ans.end(), vector<int>({unmap[str2],i})) != ans.end())
                                ans.push_back(vector<int>({unmap[str2], i}));
                        }
                    }
                    if(isPali(0, str2.size() - 1, str2)){
                        if(unmap.find(str1) != unmap.end()){
                            if(i != unmap[str1] && find(ans.begin(), ans.end(), vector<int>({i, unmap[str1]})) != ans.end())
                                ans.push_back(vector<int>({i, unmap[str1]}));
                        }
                    }
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
    vector<string> words{"a",""};
    Solution s;
    auto ans = s.palindromePairs(words);
}
