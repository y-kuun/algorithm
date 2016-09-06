#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n) {
        for (int i = m; i <= n; i++) {
            int a = i / 100;
            int b = (i % 100) / 10;
            int c = i % 10;
            if (a * a + b * b + c * c == i) {
                cout << i << endl;
            }
        }
    }
}