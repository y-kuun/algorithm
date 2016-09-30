

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();

        if (size < 4)
            return res;
        // vector<int> visited(nums.size(), 0);
        // recursion(nums, gp, res, visited, target);
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] <
                target)
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[size - 2] + nums[size - 1] <
                    target)
                    continue;

                int left = j + 1;
                int right = size - 1;
                int tt = target - nums[i] - nums[j];
                while (left < right) {
                    if (nums[left] + nums[right] > tt)
                        right--;
                    else if (nums[left] + nums[right] < tt) {
                        left++;
                    } else if (nums[left] + nums[right] == tt) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left],
                                                  nums[right]});
                        do {
                            left++;
                        } while (nums[left] == nums[left - 1] && left < right);
                        do {
                            right--;
                        } while (nums[right] == nums[right + 1] &&
                                 left < right);
                    }
                }
            }
        }
        return res;
    }
};