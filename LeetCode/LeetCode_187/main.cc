
#include <iostream>
#include <cstdlib>
#include <set>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
    public:
        set<string> ans;
        set<string> vans;
        vector<string> vs;
        string str;
        vector<string> findRepeatedDnaSequences(string s) {
            for(int i = 0; i + 9 < s.length(); i++){
                str = s.substr(i, 10);
                if(ans.find(str) == ans.end())
                    ans.insert(str);
                else vans.insert(str);
            }

            set<string>::iterator it;
            for(it = vans.begin(); it != vans.end(); it++){
                vs.push_back(*it);
            }
            return vs;
        }
};


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
