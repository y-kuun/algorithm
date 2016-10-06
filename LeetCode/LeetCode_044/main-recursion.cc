#include <iostream>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            // delete multiple *;
            bool flag;
            flag = false;
            if(s[0] == '\0' && p[0] == '\0')
                return true;
            if(s[0] == p[0]){
                return isMatch(s.substr(1), p.substr(1));
            }
            if(s[0] != '\0' && p[0] == '?'){
                return isMatch(s.substr(1), p.substr(1));
            }
            if(s[0] != '\0' && p[0] == '*'){
                int k = 1;
                while(p[0] == p[k]){
                    k++;
                }
                for(int i = 0; s[i] != '\0' && !flag ; i++){
                    if(s[i] == p[k] || p[k] == '?')
                        flag = flag | isMatch(s.substr(i), p.substr(k));
                }
                return flag;
            }else if(s[0] == '\0' && p[0] == '*'){
                return isMatch(s, p.substr(1));
            }
            return false;
        }
};
