#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    double sum = 0;
    double n;
    int m;
    while (cin >> n >> m) {
        sum = 0;
        while (m--) {
            sum += n;
            n = sqrt(n);
        }
        printf("%0.2lf\n", sum);
    }
}