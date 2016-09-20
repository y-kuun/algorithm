#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// 100%
int main() {
    // freopen("input.txt", "r+", stdin);
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    int dp0[101][101];  //  dp0[i][j] 表示原数组的 i-j 之间 我能够获得的最多
    int dp1[101][101];  //  dp1[i][j] 表示原数组的 i-j 之间 BOSS能够获得的最多
    for (int i = 0; i < n; i++) {
        dp0[i][i] = vec[i];
        dp1[i][i] = 0;
    }
    // 如果我取了 i,j 中的j 我只能够获得 i,j-1 情况中 boss获得的量
    // dp0[i][j] = max(vec[j] + dp1[i][j-1],vec[i] + dp1[i+1][j])  0 <= i,j < n
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i++) {
            int tmp0 = vec[i + k] + dp1[i][i + k - 1];
            int tmp1 = vec[i] + dp1[i + 1][i + k];
            if (tmp0 > tmp1) {
                dp0[i][i + k] = tmp0;
                dp1[i][i + k] = dp0[i][i + k - 1];
            } else {
                dp0[i][i + k] = tmp1;
                dp1[i][i + k] = dp0[i + 1][i + k];
            }
        }
    }
    cout << dp0[0][n - 1] << " " << dp1[0][n - 1] << endl;
}