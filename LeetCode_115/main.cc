#include <iostream>
#include <string>

using namespace std;

// dp[i][j] 表示以s[0~1]来匹配t[0~j]
//               s[i] used +  s[i] unused
// dp[i][j] = dp[i-1][j-1] + dp[i-1][j] if s[i] == t[j]   j-1 <= k < i
//            dp[i-1][j])               if s[i] != t[j]   j < k < i

class Solution {
   public:
    int numDistinct(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if (slen == 0 || tlen == 0) return 0;
        int dp[slen + 1][tlen + 1];

        memset(dp, 0, sizeof(dp));

        if (s[0] == t[0])
            dp[0][0] = 1;
        else {
            dp[0][0] = 0;
        }

        for (int si = 1; si < slen; si++) {
            if (s[si] == t[0]) {
                dp[si][0] = 1 + dp[si - 1][0];
            } else {
                dp[si][0] = dp[si - 1][0];
            }
        }

        for (int ti = 1; ti < tlen; ti++) {
            for (int si = ti; si < slen; si++) {
                if (s[si] == t[ti]) {
                    dp[si][ti] = dp[si - 1][ti - 1] + dp[si - 1][ti];
                } else {
                    dp[si][ti] = dp[si - 1][ti];
                }
            }
        }
        return dp[slen - 1][tlen - 1];
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("", "a") << endl;
    cout << s.numDistinct("rabbbit", "rabbit") << endl;
    cout << "1" << endl;
}