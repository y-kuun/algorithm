#include <cmath>
#include <iostream>

using namespace std;

int bitsum(int tmp) {
    int sum = 0;
    while (tmp) {
        sum += tmp % 10;
        tmp = tmp / 10;
    }
    return sum;
}

int main() {
    int A, B, C;
    int sum_c, sum_a, sum_b;
    cin >> A >> B >> C;
    sum_c = bitsum(C);

    int min_abs = 0x7FFFF;
    int loc = -1;

    for (int i = A; i <= B; i++) {
        int tmp = bitsum(i);
        int dif = abs(tmp - sum_c);
        if (dif < min_abs) {
            min_abs = dif;
            loc = i;
        }
    }
    cout << loc << endl;

    return 0;
}