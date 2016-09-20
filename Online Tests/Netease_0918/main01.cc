#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int case_num;
    int k;
    string ipt;
    cin >> case_num;
    int sum;
    while (case_num--) {
        cin >> k;
        cin >> ipt;
        sum = 0x80000000;
        int len = ipt.size();
        int n;
        int tmp;

        for (int i = 0; i <= len - k; i++) {
            n = 0;
            tmp = 0;
            while (n < len) {
                if (ipt[n] == '0' && n < i) {
                    tmp++;
                } else if (ipt[n] == '0' && n >= i + k) {
                    tmp++;
                } else if (ipt[n] == '1' && n >= i && n < i + k) {
                    tmp++;
                } else {
                    if (sum < tmp) {
                        sum = tmp;
                    }
                    tmp = 0;
                }
                n++;
            }
            if (sum < tmp) {
                sum = tmp;
            }
        }
        cout << sum << endl;
    }
    return 0;
}