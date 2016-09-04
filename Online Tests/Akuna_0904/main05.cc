/*
 * Complete the function below.
 */

#include <iostream>
#include <string>
using namespace std;

string convert_to_binary_string(int value) {
    string res("");

    int tmp;
    if (value < 0) {
        tmp = value * -1;
    } else
        tmp = value;
    while (tmp) {
        if (tmp & 0x01) {
            res = "1" + res;
        } else {
            res = '0' + res;
        }
        tmp = tmp >> 1;
    }
    if (value < 0)
        return "-" + res;
    else
        return res;
}
int main() {
    int n;
    cin >> n;
    cout << convert_to_binary_string(n);
    return 0;
}
