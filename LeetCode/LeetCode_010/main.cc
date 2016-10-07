#include <string>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        if (lenp == 0 && lens != 0) {
            return false;
        }
        if (lens == 0) {
            for (auto ch : p) {
                if (ch != '.' || ch != '*') return false;
            }
            return true;
        }
        int si = 0;
        int pi = 0;
        while (si < lens && pi < lenp) {
            if (s[si] == p[pi]) {
                if (pi + 1 < lenp && p[pi] == '*') {
                    bool ans = false;
                    for (int i = 0; !ans; i++) {
                        ans = isMatch(s.substr(si + i, lens - si - i + 1),
                                      p.substr(pi + 2, lenp - pi - 1));
                    }
                    return ans;
                } else {
                    si++;
                    pi++;
                }
            } else if (p[pi] == '.') {
                return isMatch(s.substr(si + 1, lens - si - 1),
                               p.substr(pi, lenp - pi - 1));
            } else if (pi + 1 < lenp && p[pi + 1] == '*') {
                // 如果当前的值不想等，而pattern之后是一个*那么跳过不相关的pattern
                return isMatch(s.substr(si), p.substr(pi + 2, lenp - pi - 1));
            } else {
                return false;
            }
        }
        // 长度到头了
        if (si == lens && pi == lenp) {
            return true;
        }
        if (si == lens) {
            return isMatch(s.substr(si, 0), p.substr(pi, lenp - pi)));
        } else {
            return false;
        }
        //
    }
};