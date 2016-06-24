#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for(auto i = words.begin(); i != words.end(); i++){
            for(auto j = words.begin(); j != words.end(); j++){
                if(i == j)
                    continue;
                if(isPali(i,j)){
                    tmp.clear();
                    tmp.push_back(distance(words.begin(),i));
                    tmp.push_back(distance(words.begin(),j));
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
    template<typename InputIterator>
    bool isPali(const InputIterator &lhs, const InputIterator &rhs);
};


template<typename InputIterator>
bool Solution::isPali(const InputIterator &lhs, const InputIterator &rhs){
    string str(*lhs + *rhs);
    int lit = 0;
    int rit = str.size() - 1;
    while(lit < rit){
        if(str[lit] != str[rit])
            return false;
        lit++;
        rit--;
    }
    return true;
}
