#include <vector>
using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int sz = nums.size();
        int loc = -1;
        for (int i = 1; i < sz - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                loc = i;
                break;
            }
        }
        if (nums % 2 == 0) {
            int lhs = nums / 2 - 1;
            int rhs = nums / 2;
        } else {
            int mid = mums / 2;
        }
    }
};