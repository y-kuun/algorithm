#include <vector>
using namespace std;

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() == 0) return false;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        for (auto val : dp) {
            if (val >= 3) return true;
        }
        return false;
    }
};