#include <string>
using namespace std;

// greedy for a + b = c;
// begin a = 1 digital bit b = 1 digital bit and then inc 1 bit one by one to
// check untill there is not for big left
// how to handle the  overflow?
// it is string originally, so let do big int plus

class Solution {
   public:
    string add(int aloc, int alen, int bloc, int blen, string num) {
        string res;
        int alow = aloc + alen - 1;
        int blow = bloc + blen - 1;
        int carry = 0;
        int tmp;
        while (alow >= aloc && blow >= bloc) {
            tmp = num[alow] - '0' + num[blow] - '0' + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            char ch = '0' + tmp;
            res = res + ch;
        }
        while (alen) {
            tmp = num[alow] char ch = '0'
        }
    }
    bool isAdditiveNumber(string num) {
        int str_size = num.size();
        int aloc = 0;
        int alen = 1;
        int bloc = aloc + alen;
        int blen = 1;
    }
};