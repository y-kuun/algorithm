// Exam2 Wireless ROuters
// Author:  Yukun Du
// Date:    2010-10-03
// Description: all the N room with N-1 door can be regarded as a binary tree

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static int dp[1001][101][3];    // for the tree dp
static int room_map[1001][1001];
static int room_point[1001];
static int n, m;

bool walker(int cur_id) {
    if (cur_id == -1) {
        return false;
    }
    int left = -1;
    int right = -1;
    for (int i = 0; i <= n; i++) {
        if (room_map[cur_id][i] == 1) {
            room_map[cur_id][i] = room_map[i][cur_id] = 0;
            if (left == -1) {
                left = i;
            } else
                right = i;
        }
    }

    walker(left);
    walker(right);

    // if current node is a leave node
    if (left == -1 && right == -1) {
        for (int i = 1; i <= m; i++) {
            dp[cur_id][i][2] = room_point[cur_id - 1];
        }
        return false;
    }

    // if current node is not a leave node
    // situation 1: current node is not picked and no wifi
    for (int i = 0; i <= m; i++) {
        int sum = 0;
        int lval = 0;
        int rval = 0;
        for (int j = 0; j <= i; j++) {
            if (left != -1)
                lval = dp[left][j][0];
            else
                lval = 0;
            if (right != -1)
                rval = dp[right][i - j][0];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
        }
        dp[cur_id][i][0] = sum;
    }
    // situation 2: current node is not picked but at least one of his child
    // has;
    for (int i = 0; i <= m; i++) {
        int sum = 0;
        int lval = 0;
        int rval = 0;
        for (int j = 0; j <= i; j++) {
            if (left != -1) {
                for (int k = 0; k < 3; k++) {
                    if (lval < dp[left][j][k]) {
                        lval = dp[left][j][k];
                    }
                }
            } else {
                lval = 0;
            }
            if (right != -1) {
                for (int k = 0; k < 3; k++) {
                    if (rval < dp[right][i - j][k]) {
                        rval = dp[right][i - j][k];
                    }
                }
            } else {
                rval = 0;
            }
            int tmp;
            if (right == -1)
                tmp = dp[left][j][2];
            else if (left == -1) {
                tmp = dp[right][m - j][2];
            } else {
                tmp = max(dp[left][j][2] + rval, dp[right][m - j][2] + lval);
            }
            if (sum < tmp) {
                sum = tmp;
            }
        }
        if (i != 0)
            dp[cur_id][i][1] = sum + room_point[cur_id - 1];
        else
            dp[cur_id][i][1] = sum;
    }
    // pick the current one, and no matter his children's situation
    for (int i = 0; i <= m; i++) {
        int sum = 0;
        int lval = 0;
        int rval = 0;
        // the choose all children of current node share i - 1 wifi router(s)
        for (int j = 0; j < i; j++) {
            if (left != -1) {
                for (int k = 0; k < 3; k++) {
                    if (k == 0) {
                        if (lval < dp[left][j][k] + room_point[left-1]) {
                            lval = dp[left][j][k] + room_point[left-1];
                        }
                    } else {
                        if (lval < dp[left][j][k]) {
                            lval = dp[left][j][k];
                        }
                    }
                }
            } else {
                lval = 0;
            }
            if (right != -1) {
                for (int k = 0; k < 3; k++) {
                    if (rval < dp[right][i - j][k]) {
                        rval = dp[right][i - j][k];
                    }
                    if (k == 0) {
                        if (rval < dp[right][i - j][k] + room_point[right-1])
                            rval = dp[right][i - j][k] + room_point[right-1];
                    }
                }
            } else {
                rval = 0;
            }
            auto tmp = rval + lval;
            if (sum < tmp) {
                sum = tmp;
            }
        }
        if (i != 0)
            dp[cur_id][i][2] = sum + room_point[cur_id - 1];
        else
            dp[cur_id][i][2] = sum;
    }
    return true;
}

void print_map() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << room_map[i][j] << " ";
        }
        cout << endl;
    }
}

void print_dp(int k) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j][k] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    // read from a input file
    freopen("input.txt", "r+", stdin);
    cin >> n >> m;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < 1001; i++) {
        room_point[i] = 0;
        for (int j = 0; j < 1001; j++) {
            room_map[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> room_point[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        room_map[x][y] = 1;
        room_map[y][x] = 1;
    }

    // there must be a node with degree 1, we choose it to generate the binary
    // tree

    int root_id;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += room_map[i][j];
        }
        if (degree == 1) {
            root_id = i;
            break;
        }
    }

    walker(root_id);

    auto ans = max(dp[root_id][m][0], dp[root_id][m][1]);

    ans = max(ans, dp[root_id][m][2]);

    cout << ans << endl;

    return 0;
}
