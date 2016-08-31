#include <climits>
#include <vector>
using namespace std;

class Solution {
  public:
    int max(int x, int y) { return x > y ? x : y; }
    int min(int x, int y) { return x < y ? x : y; }
    int maxProduct(vector<int> &nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1) {
            return nums[0];
        }
        int dp[size][2];
        if (nums[0] >= 0) {
            dp[0][1] = nums[0];
            dp[0][0] = 0;
        } else {
            dp[0][0] = nums[0];
            dp[0][1] = 0;
        }

        for (int i = 1; i < size; i++) {
            if (nums[i] > 0) {
                dp[i][0] = min(dp[i - 1][0] * nums[i], nums[i]);
                dp[i][1] = max(dp[i - 1][1] * nums[i], nums[i]);
            } else if (nums[i] < 0) {
                dp[i][0] = min(dp[i - 1][1] * nums[i], nums[i]);
                dp[i][1] = max(dp[i - 1][0] * nums[i], nums[i]);
            } else if (nums[i] == 0) {
                dp[i][0] = 0;
                dp[i][1] = 0;
            }
        }
        int max_val = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (dp[i][0] > max_val) {
                max_val = dp[i][0];
            }
            if (dp[i][1] > max_val) {
                max_val = dp[i][1];
            }
        }
        return max_val;
    }
};