// dp，进行划分，选择与不选择，dp问题从一维入手，升入高维

#include <vector>
using namespace std;

class Solution {
  public:
    int max(int x, int y) { return x > y ? x : y; };
    int rob(vector<int> &nums) {

        int house_num = nums.size();

        if (house_num == 0)
            return 0;

        int dp[house_num][2];

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for (int i = 1; i < house_num; i++) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
        }

        return max(dp[house_num - 1][0], dp[house_num - 1][1]);
    }
};