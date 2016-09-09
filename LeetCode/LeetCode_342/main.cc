
class Solution {
  public:
    bool isPowerOfFour(int num) {
        if (num == 0 || num == 2)
            return false;
        int val = num - 1;
        if (val > num)
            return false;
        int flag = num & (num - 1);
        if (flag != 0)
            return false;
        int tmp = sqrt(num);
        if (tmp * tmp < num)
            return false;
        return !((tmp) & (tmp - 1));
    }
};