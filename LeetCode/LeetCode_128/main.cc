#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (auto i : nums) {
            us.insert(i);
        }
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = 1;
            int k = nums[i] - 1;
            while (us.find(k) != us.end()) {
                us.erase(k);
                k--;
                tmp++;
            }
            k = nums[i] + 1;
            while (us.find(k) != us.end()) {
                us.erase(k);
                k++;
                tmp++;
            }
            if (tmp > max) {
                max = tmp;
            }
        }
        return max;
    }
};