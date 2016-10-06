#include <iostream>
#include <set>
#include <vector>

using namepsace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mingap = 0x7FFFFFFF;
        int res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int n = i + 1;
            int m = nums.size() - 1;
            while (n < m) {
                int sum = nums[i] + nums[n] + nums[m];
                int gap = abs(target - sum);

                if (gap < mingap) {
                    mingap = gap;
                    res = sum;
                }
                if (sum > target) {
                    m--;
                } else
                    n++;
            }
        }
        return res;
    }
};