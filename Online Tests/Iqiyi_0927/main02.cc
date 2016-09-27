#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(int argc, char** argv) {
    freopen("input", "r+", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> cost(m);
    vector<int> damage(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cost[i] = a;
        damage[i] = b;
    }
    vector<vector<int> > dp(m);
    for (int i = 0; i < m; i++) {
        dp[i] = vector<int>(n + 1, 0);
    }

    for (int i = 0; i <= n; i++) {
        if (i >= cost[0]) dp[0][i] = damage[0];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (cost[i] <= j)
                dp[i][j] =
                    max(dp[i - 1][j - cost[i]] + damage[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[m - 1][n] << endl;
    return 0;
}