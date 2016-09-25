#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(int argc, char** argv) {
    freopen("input", "r+", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> value(n);
    vector<int> weight(n);
    vector<vector<int> > dp(n);

    for (int i = 0; i < n; i++) {
        dp[i] = vector<int>(m + 1, 0);
    }

    int ipt1, ipt2;
    for (int i = 0; i < n; i++) {
        cin >> ipt1 >> ipt2;
        weight[i] = ipt1;
        value[i] = ipt2;
    }

    for (int j = 0; j <= m; j++) {
        if (j >= weight[0]) dp[0][j] = value[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (weight[i] <= j) {
                dp[i][j] =
                    max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
            }
        }
    }

    cout << dp[n - 1][m] << endl;
    return 0;
}