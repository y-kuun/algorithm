#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        string ans("");
        int len = s.size();
        if (0 == len) {
            return ans;
        }
        for (int i = 0; i < len; i++) {
            int left = i;
            int right = i;
            while (left >= 0 && s[left] == s[i]) {
                left--;
            }
            while (right < len && s[i] == s[right]) {
                right++;
            }
            // 这个时候不需要越界进行处理
            while (left >= 0 && right < len && s[left] == s[right]) {
                left--;
                right++;
            }
            // 如果一个越界，那么当前比较的的left 和 right值都不能够使用
            // 否则如何left和right所指的位置不是我们所需要的
            string tmp = s.substr(left + 1, right - left - 1);
            if (tmp.size() > ans.size()) {
                ans = tmp;
            }
        }
        return ans;
    }
};