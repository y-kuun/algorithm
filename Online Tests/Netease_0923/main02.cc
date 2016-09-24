#include <cmath>
#include <iostream>

using namespace std;

// 80%
int bitcount(unsigned int n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    int target_weight = bitcount(N);
    int back_zero = 0;
    int continous_one = 0;
    int first_one;
    int tmp = N;
    while (!(tmp & 0x1)) {
        back_zero++;
        tmp = tmp >> 1;
    }
    while (tmp & 0x1) {
        continous_one++;
        tmp = tmp >> 1;
    }
    first_one = continous_one + back_zero;
    tmp = N;
    tmp = tmp | (0x1 << first_one);
    tmp = tmp - (0x1 << (first_one - 1));
    if (back_zero != 0) {
        for (int i = 1; i < continous_one; i++) {
            tmp = tmp & (tmp - 1);
        }
        for (int i = 0; i < continous_one - 1; i++) {
            tmp = tmp | (0x1 << i);
        }
    }
    cout << tmp << endl;
    return 0;
}