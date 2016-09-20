#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string str;
        for (int i = 0; i < nums.size();) {
            str.clear();
            str = str + to_string(nums[i]);
            int tmp = i;
            while (tmp + 1 < nums.size() && nums[tmp] + 1 == nums[tmp + 1]) {
                tmp++;
            }
            if (tmp == i) {
                ans.push_back(str);
            } else {
                str = str + "->" + to_string(nums[tmp]);
                ans.push_back(str);
                i = tmp;
            }
            i++;
        }
        return ans;
    }
};