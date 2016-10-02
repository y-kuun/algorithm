#include <unordered_set>
#include <vector>

using namespace std;

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int ceil = 1 << n;
        for (int i = 0; i < ceil; i++) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};
/*
class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        int ceil = 1 << n;
        int k = 0;
        unordered_set<int> us;
        us.insert(k);
        int base = 0x1;
        int shift = -1;
        int tmp;
        for (int i = 0; i < ceil; i++) {
            for (int j = 0; j < n; j++) {
                if (j == shift) continue;
                int flag = k & (base << j);
                if (flag) {
                    // 该位为1
                    tmp = k - (base << j);
                } else {
                    // 该位为0
                    tmp = k | (base << j);
                }
                if (us.find(tmp) == us.end()) {
                    us.insert(tmp);
                    ans.push_back(tmp);
                    k = tmp;
                    shift = j;
                    break;
                } else {
                    continue;
                }
            }
        }
        return ans;
    }
};
*/