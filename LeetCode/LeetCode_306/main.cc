#include <iostream>
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
        string str("");
        int alow = aloc + alen - 1;
        int blow = bloc + blen - 1;
        int carry = 0;
        int tmp;
        while (alow >= aloc && blow >= bloc) {
            tmp = num[alow] - '0' + num[blow] - '0' + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            char ch = '0' + tmp;
            str += ch;
            alow--;
            blow--;
        }

        while (alow >= aloc) {
            tmp = num[alow] - '0' + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            char ch = '0' + tmp;
            str += ch;
            alow--;
        }

        while (blow >= bloc) {
            tmp = num[blow] - '0' + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            char ch = '0' + tmp;
            str += ch;
            blow--;
        }

        if (carry != 0) {
            char ch = '0' + carry;
            str += ch;
        }
        return str;
    }

    bool check_strs(string res, int loc, int len, string num) {
        int nlow = loc + len - 1;
        int rlow = 0;
        while (nlow >= 0 && rlow < res.size()) {
            if (res[rlow++] != num[nlow--]) return false;
        }
        return true;
    }

    bool isAdditiveNumber(string num) {
        int str_size = num.size();

        if (str_size < 3) {
            return false;
        }

        // state initialization
        int aloc;
        int alen;
        int bloc;
        int blen;
        int cloc;
        int clen;
        string res;

        // it is very improtant to find the first two;
        for (int total_len = 2; total_len < str_size; total_len++) {
            for (int i = 1; i < total_len; i++) {
                int loc1 = 0;
                int len1 = i;
                int loc2 = loc1 + len1;
                int len2 = total_len - len1;

                aloc = loc1;
                alen = len1;
                bloc = loc2;
                blen = len2;
                cloc = bloc + blen;
                if ((num[aloc] == '0' && alen != 1) ||
                    (num[bloc] == '0' && blen != 1))
                    continue;
            loop:
                res = add(aloc, alen, bloc, blen, num);
                clen = res.size();
                if (clen > (str_size - cloc))
                    continue;
                else if (clen == (str_size - cloc)) {
                    if (check_strs(res, cloc, clen, num)) {
                        return true;
                    } else {
                        continue;
                    }
                } else {
                    if (check_strs(res, cloc, clen, num) == false) {
                        continue;
                    } else {
                        // the first two is found;
                        // check the rest of the nums;
                        aloc = bloc;
                        alen = blen;
                        bloc = cloc;
                        blen = clen;
                        cloc = bloc + blen;
                        goto loop;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    string req;
    while (cin >> req) {
        cout << s.isAdditiveNumber(req) << endl;
    }
    cout << s.isAdditiveNumber("112359") << endl;
    cout << s.isAdditiveNumber("199100199") << endl;
}