#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int base = 0x1;
        for (int i = 0; i < 32; i++) {
            int tmp = 0;
            for (auto val : nums) {
                tmp += (val & (base << i)) ? 1 : 0;
            }
            if (tmp % 3) {
                res = res | (base << i);
            }
        }
        return res;
    }
};