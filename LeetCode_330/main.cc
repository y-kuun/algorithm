#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    int minPatches(vector<int>& nums, int n) {
        // Gready
        // 注意问题需要考虑
        int cnt = 0;
        int sum = 0;
        if (nums.size() != 0) {
            sort(nums.begin(), nums.end());
        }
        int i = 0;
        while (sum < n && sum >= 0) {
            if (i < nums.size() && sum >= nums[i] - 1)) {
                sum = sum + nums[i++];
            }
            else {
                sum = sum + sum + 1;
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> vec{1, 2, 31, 33};
    s.minPatches(vec, 2147483647);
}