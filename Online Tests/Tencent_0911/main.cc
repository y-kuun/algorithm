#include <cstdio>
#include <vector>
using namespace std;

int main() {
    double num;
    scanf("%lf", &num);
    vector<int> ans(6, 0);
    int left = -90;
    int right = 90;
    int mid = 0;
    for (int i = 0; i < 6; i++) {
        mid = (left + right) / 2;
        if (num >= left && num < mid) {
            ans[i] = 0;
            right = mid;
        } else if (num >= mid && num <= right) {
            ans[i] = 1;
            left = mid;
        }
    }

    for (int i = 0; i < 6; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
}