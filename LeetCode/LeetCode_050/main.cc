#include <iostream>
using namespace std;

class Solution {
   public:
    double helper(double x, int n) {
        bool neg_flag = false;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;

        if (n < 0) {
            neg_flag = true;
            if (n == 0x80000000) {
                n = 0x80000002;
            }
            n = -1 * n;
        }

        double rtn;
        int tmp = n / 2;
        double res = helper(x, tmp);
        if (n % 2 == 0) {
            rtn = res * res;
        } else {
            rtn = res * res * x;
        }

        if (neg_flag) {
            return 1 / rtn;
        } else
            return rtn;
    }
    double myPow(double x, int n) { return helper(x, n); }
};

int main() {
    Solution s;
    double x;
    int n;
    cin >> x >> n;
    cout << s.myPow(x, n) << endl;

    return 0;
}