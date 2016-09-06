#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    string res;
    unsigned long long k;
    unsigned long long tmp;
    unsigned long long base = 1;
    while (t--) {
        tmp = 0;
        cin >> k;
        while (k >= (base << tmp) - 1) {
            tmp++;
        }

        tmp = tmp - 1;
        unsigned long long start_pos = (base << tmp) - 1;

        res.clear();
        for (int i = 0; i < tmp; i++) {
            res += "4";
        }

        for (int i = tmp - 1; i >= 0; i--) {
            if (start_pos + (base << i) < k) {
                res[tmp - 1 - i] = '7';
                start_pos += base << i;
            } else if (start_pos + (base << i) == k) {
                res[tmp - 1 - i] = '7';
                cout << res << endl;
                break;
            } else {
                if (i == 0) cout << res << endl;
                continue;
            }
        }
    }
    return 0;
}