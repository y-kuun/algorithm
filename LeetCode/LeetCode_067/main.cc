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
    string addBinary(string a, string b) {
        string ans;
        int enda = 0;
        int endb = 0;
        auto it = a.begin();
        while (it != a.end() - 1 && *it == '0') {
            enda++;
            it++;
        }
        it = b.begin();
        while (it != b.end() - 1 && *it == '0') {
            it++;
            endb++;
        }
        int lena = a.size() - 1;
        int lenb = b.size() - 1;
        int carry = 0;
        while (lena >= enda && lenb >= endb) {
            int tmp = a[lena] - '0' + b[lenb] - '0' + carry;
            carry = tmp / 2;
            tmp = tmp % 2;
            ans += tmp + '0';
            lena--;
            lenb--;
        }
        while (lena >= enda) {
            int tmp = a[lena] - '0' + carry;
            carry = tmp / 2;
            tmp = tmp % 2;
            ans += tmp + '0';
            lena--;
        }
        while (lenb >= endb) {
            int tmp = b[lenb] - '0' + carry;
            carry = tmp / 2;
            tmp = tmp % 2;
            ans += tmp + '0';
            lenb--;
        }
        if (carry) {
            ans = ans + '1';
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char** argv) {
    freopen("input", "r+", stdin);
    string str1;
    string str2;
    Solution s;
    while (cin >> str1 >> str2) {
        s.addBinary(str1, str2);
    }
}