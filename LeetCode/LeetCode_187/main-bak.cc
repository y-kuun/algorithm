#include <iostream>
#include <cstdlib>
#include <set>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct chnode{
    int count;
    string str;
    chnode *next_lay[4];
    chnode(){
        this->next_lay[0] = NULL;
        this->next_lay[1] = NULL;
        this->next_lay[2] = NULL;
        this->next_lay[3] = NULL;
        this->count = 0;
        this->str.clear();
    }
}chnode, *chtree;

class Solution {
    public:
        chtree head;
        set<string> ans;
        vector<string> vans;
        vector<string> findRepeatedDnaSequences(string s) {
            for(int i = 0; i + 9 < s.length(); i++)
                tree_built(head, i, i + 9, s);
            set<string>::iterator it;
            for(it = ans.begin(); it != ans.end(); it++){
                vans.push_back(*it);
            }
            return vans;
        }
        Solution(){
            head = new chnode;
        }
        bool dfs(set<string> &ans, chtree p);
        bool tree_built(chtree head, int begin, int end, string s);
};

bool Solution::dfs(set<string> &ans, chtree p){
    if(p == NULL)
        return true;
    for(int i = 0; i < 4; i++){
        if(dfs(ans, p->next_lay[i]) && p->str.length() == 10 && p->count > 1)
            ans.insert(p->str);
    }
    return false;
}

bool Solution::tree_built(chtree head, int begin, int end, string s){
    int tmp;
    if(end - begin + 1 != 10)
        return false;
    chtree p = head;
    string str_tmp;
    for(int i = begin; i <= end; i++){
        switch(s[i]){
            case 'A': tmp = 0; break;
            case 'C': tmp = 1; break;
            case 'G': tmp = 2; break;
            case 'T': tmp = 3; break;
            default: break;
        }
        if(p->next_lay[tmp] == NULL){
            str_tmp = p->str + s[i];
            p->next_lay[tmp] = new chnode;
            p = p->next_lay[tmp];
            p->count++;
            p->str= str_tmp;
        } else {
            p = p->next_lay[tmp];
            p->count++;
        }
        if(p->count > 1 && i == end)
            ans.insert(p->str);
    }
    return true;
}

int main(){
    freopen("input","r",stdin);
    Solution S;
    string s;
    vector<string> vs;
    cin>>s;
    vs = S.findRepeatedDnaSequences(s);
    for(int i = 0; i < vs.size(); i++)
       cout<<vs[i]<<endl;
    return 0;
}
