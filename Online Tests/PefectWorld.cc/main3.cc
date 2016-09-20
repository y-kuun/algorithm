#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r+", stdin);
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    vector<int> dp[2](n, 0);
    int l0, h0;
    int l1, h1;
    l0 = l1 = 0;
    h0 = h1 = n - 1;
    int cnt = 0;
    while (l0 < h0) {
        dp[0][]
    }
}