#include <cmath>
#include <iostream>
using namespace std;

class Solution {
   public:
    int getLen(unsigned tmp) {
        int cnt = 0;
        while (tmp) {
            tmp = tmp >> 1;
            cnt++;
        }
        return cnt;
    }
    int divide(int dividend, int divisor) {
        long long dend = dividend;
        long long dsor = divisor;
        int len1;
        int len2;
        if (dsor == 0) {
            return 0;
        }
        bool flag = false;
        int spe_num = 0;
        if (dend < 0) {
            dend = 0 - dend;
            if (!flag)
                flag = true;
            else
                flag = false;
        }
        if (dsor < 0) {
            dsor = 0 - dsor;
            if (!flag)
                flag = true;
            else
                flag = false;
        }

        len1 = getLen(dend);
        len2 = getLen(dsor);
        if (len1 < len2) {
            return 0;
        }
        int res = 0;
        while (dsor <= dend) {
            int cnt = len1 - len2;
            int dif = dend - (dsor << cnt);
            if (dif >= 0) {
                res += 1 << cnt;
                dend = dif;
                len1 = getLen(dend);
            } else if (dif < 0) {
                cnt = cnt - 1;
                res += 1 << cnt;
                dend -= dsor << cnt;
                len1 = getLen(dend);
            }
        }
        if (flag) {
            return 0 - res;
        } else
            return res < 0 ? 0x7FFFFFFF : res;
    }
};

int main() {
    Solution s;
    int d1, d2;
    while (cin >> d1 >> d2) {
        cout << s.divide(d1, d2) << endl;
    }
}