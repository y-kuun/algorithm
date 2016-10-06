#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int i = 0, j = 0;
            int ii;  // before ii all the chars had been matched!
            int asterisk = -1;
            while(s[i] != '\0'){
                if( s[i] == p[j] || p[j] == '?'){
                    i++;
                    j++;
                    continue;
                }
                if(p[j] == '*'){
                    asterisk = j++;
                    ii = i;
                    continue;
                }
                if(asterisk != -1){
                    j = asterisk + 1;
                    i = ++ii;
                    continue;
                }
                return false;
            }
            while(p[j] == '*'){
                j++;
            }
            return p[j] == '\0';
        }
};

int main(){
    string s("abcd");
    string p("*");
    Solution ss;
    cout<<ss.isMatch(s,p);
}
