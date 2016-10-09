

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                break;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        if (nums[mid] != target) {
            return vector<int>{-1, -1};
        }
        left = mid;
        right = mid;
        while (left >= 0 && nums[left] == nums[mid]) {
            left--;
        }
        while (right < nums.size() && nums[right] == nums[mid]) {
            right++;
        }
        return vecotr<int>{left, right};
    }
};