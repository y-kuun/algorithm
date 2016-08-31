#include <vector>
using namespace std;

class Solution {
   public:
    int findMin(vector<int> &nums) {
        int lhs, rhs;
        int sz = nums.size();
        if (sz == 0) return 0;
        if (sz == 1) return nums[0];
        if (sz == 2) return nums[0] > nums[1] ? nums[1] : nums[0];

        int loc = -1;
        for (int i = 1; i < sz - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                loc = i;
                break;
            }
        }
        return nums[loc + 1];
    }
};