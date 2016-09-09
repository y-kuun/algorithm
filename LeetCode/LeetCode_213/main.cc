// dp，进行划分，选择与不选择，dp问题从一维入手，升入高维
// break the chain for assuming one node is not robbed;

#include <vector>
using namespace std;

class Solution {
  public:
    int max(int x, int y) { return x > y ? x : y; };
    int rob(vector<int> &nums) {

        int house_num = nums.size();

        if (house_num == 0)
            return 0;

        if (house_num == 1)
            return nums[0];

        int dp[house_num][2];

        dp[1][0] = 0;
        dp[1][1] = nums[1];

        for (int i = 2; i < house_num; i++) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
        }

        int res0 = max(dp[house_num - 1][0], dp[house_num - 1][1]);

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for (int i = 1; i < house_num - 1; i++) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
        }

        int res1 = max(dp[house_num - 2][0], dp[house_num - 2][1]);

        return max(res0, res1);
    }
};