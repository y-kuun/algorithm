#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int isPali(const string& str, int left, int right, int loc) {
    while (left < right) {
        if (str[left] != str[right] && loc == -1) {
            int tmp0 = isPali(str, left + 1, right, left);
            int tmp1 = isPali(str, left, right - 1, right);
            if (tmp0 != -2)
                return left;
            else if (tmp1 != -2)
                return right;
        } else if (str[left] != str[right]) {
            return -2;
        }
        left++;
        right--;
    }
    return loc;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int case_num;
    int left, right;
    int loc;
    cin >> case_num;
    string ipt_string;
    while (case_num--) {
        cin >> ipt_string;
        int len = ipt_string.size();
        left = 0;
        right = len - 1;
        loc = -1;
        cout << isPali(ipt_string, left, right, loc) << endl;
    }
    return 0;
}
