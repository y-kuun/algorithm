// Exam2 Wireless ROuters
// Author:  Yukun Du
// Date:    2010-10-03
// Description: all the N room with N-1 door can be regarded as a binary tree

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dp[1001][101][3] = {0};  // for the tree dp
int n, m;

bool walker(int cur_id, vector<vector<int>> &room_map,
            vector<int> &room_point) {
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

    walker(left, room_map, room_point);
    walker(right, room_map, room_point);

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
        int lval;
        int rval;
        for (int j = 0; j <= i; j++) {
            if (left != -1)
                lval = dp[left][j][0];
            else
                lval = 0;
            if (right != -1)
                rval = dp[right][m - j][0];
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
                    if (rval < dp[left][j][k]) {
                        rval = dp[left][i][k];
                    }
                }
            } else {
                lval = 0;
            }
            if (right != -1) {
                for (int k = 0; k < 3; k++) {
                    if (rval < dp[left][m - j][k]) {
                        rval = dp[left][m - i][k];
                    }
                }
            } else {
                rval = 0;
            }
            auto tmp = max(dp[left][j][2] + rval, dp[left][m - j][2] + lval);
            if (sum < tmp) {
                sum = tmp;
            }
        }
        dp[cur_id][i][1] = sum + room_point[cur_id - 1];
    }
    // pick the current one, and no matter his children's situation
    for (int i = 0; i <= m; i++) {
        int sum = 0;
        int lval;
        int rval;
        // the choose all children of current node share i - 1 wifi router(s)
        for (int j = 0; j < i; j++) {
            if (left != -1) {
                for (int k = 0; k < 3; k++) {
                    if (rval < dp[left][j][k]) {
                        rval = dp[left][i][k];
                    }
                }
            } else {
                lval = 0;
            }
            if (right != -1) {
                for (int k = 0; k < 3; k++) {
                    if (rval < dp[left][m - j][k]) {
                        rval = dp[left][m - i][k];
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
        dp[cur_id][i][2] = sum + room_point[cur_id - 1];
    }
    return true;
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

    vector<int> room_point(n + 1);
    vector<vector<int>> room_map(n + 1);

    for (auto &i : room_map) {
        i = vector<int>(n + 1, 0);
    }

    for (int i = 0; i < n; i++) {
        cin >> room_point[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        room_map[x][y] = room_map[y][x] = 1;
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

    walker(root_id, room_map, room_point);

    auto ans = max(dp[root_id][m][0], dp[root_id][m][1]);

    ans = max(ans, dp[root_id][m][2]);

    cout << ans << endl;

    return 0;
}
