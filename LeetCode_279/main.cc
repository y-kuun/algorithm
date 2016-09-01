#include <vector>
using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        if (n < 0) return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = sqrt(i);
            for (int j = 1; j <= tmp; j++) {
                if (dp[i] > dp[i - (j * j)] + 1) dp[i] = dp[i - (j * j)] + 1;
            }
        }
        return dp[n];
    }
};