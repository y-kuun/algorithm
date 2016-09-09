#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int s_len = s.length();
            int p_len = s.length();
            vector<bool> dp(s_len + 1, false);
            dp[0] = true;
            for(int j = 1; j <= p_len; j++){
                bool pre = dp[0];
                dp[0] = dp[0] && p[j-1] == '*';
                for(int i = 1; i <= s_len; i++){
                    bool tmp = dp[i];
                    if(p[j-1] != '*')
                        dp[i] = pre && (s[i-1] == p[j-1] || p[j-1] == '?');
                    else dp[i] = dp[i - 1] || dp[i];
                    pre = tmp;
                }
            }
            return dp[s_len];
        }
};
