#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
   public:
    int myAtoi(string str) {
        for (auto it = str.begin(); it != str.end();) {
            if (*it == ' ') {
                str.erase(it);
            } else
                break;
        }
        bool flag = false;
        long long res = 0;
        long long overflow = 0x80000000;
        cout << str << endl;
        for (int i = 0; i < str.size(); i++) {
            if (i == 0 && (str[i] == '-' || str[i] == '+')) {
                flag = str[i] == '-';
            } else if (isdigit(str[i])) {
                long long tmp = str[i] - '0';
                res = res * 10 + tmp;
                if (res > overflow) {
                    break;
                }
            } else {
                break;
            }
        }
        if (res > overflow) {
            res = overflow;
        }
        if (res == overflow) {
            if (flag)
                return 0x80000000;
            else
                return 0x7FFFFFFF;
        } else
            return flag ? 0 - res : res;
    }
};

int main(int argc, char** argv) {
    string str;
    Solution s;
    cout << s.myAtoi("     010") << endl;
    while (cin >> str) {
        cout << s.myAtoi(str) << endl;
    }
    return 0;
}