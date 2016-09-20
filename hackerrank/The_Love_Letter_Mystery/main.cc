#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int isPali(const string& str, int left, int right) {
    int ans = 0;
    while (left < right) {
        if (left != right) {
            ans += abs(str[left] - str[right]);
        }
        left++;
        right--;
    }

    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int case_num;
    int left, rihgt;
    int loc;
    cin >> case_num;
    string ipt_string;
    string str_lhs, str_rhs;
    while (case_num--) {
        cin >> ipt_string;
        int len = ipt_string.size();
        int cnt = 0;
        if (len % 2 == 0) {
            str_lhs = ipt_string.substr(0, len / 2);
            str_rhs = ipt_string.substr(len / 2, len / 2);
            unordered_multiset lus(str_lhs.begin(), str_lhs.end());
            unordered_multiset rus(str_rhs.begin(), str_rhs.end());
            for(auto it = lus; it != lus.end();){
            }
        } else {
            str_lhs = ipt_string.substr(0, len / 2);
            str_rhs = ipt_string.substr(len / 2 + 1, len / 2);
        }

        cout << isPali(ipt_string, left, right) << endl;
    }
    return 0;
}
