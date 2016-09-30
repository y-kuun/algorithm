
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>(0);
        }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int n = i + 1;
            int m = nums.size() - 1;
            while (n < m) {
                int sum = nums[i] + nums[n] + nums[m];
                if (sum == 0) {
                    res.push_back(vector<int>{nums[i], nums[n], nums[m]});
                    n++;
                    m--;
                    while (n < m && nums[m] == nums[m + 1]) m--;
                    while (n < m && nums[n] == nums[n - 1]) n++;
                } else if (sum > 0) {
                    m--;
                    while (n < m && nums[m] == nums[m + 1]) m--;
                } else if (sum < 0) {
                    n++;
                    while (n < m && nums[n] == nums[n - 1]) n++;
                }
            }
        }
        return res;
    }
};