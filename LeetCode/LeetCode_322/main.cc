
#include <climits>
using namespace std;

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = INT_MAX;
            for (auto cns : coins) {
                if (i - cns > 0 && dp[i] > dp[i - cns] && dp[i - cns] != 0) {
                    dp[i] = dp[i - cns] + 1;
                } else if (i - cns == 0) {
                    dp[i] = 1;
                }
            }
            if (dp[i] == INT_MAX) {
                dp[i] = 0;
            }
        }
        return dp[amount] == 0 ? -1 : dp[amount];
    }
};