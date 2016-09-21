#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef struct location {
    int x;
    int y;
    int flag;  // 0 for null, 1 for up,  2 for down, 3 for left, 4 for
               // left
    location(int _x = 0, int _y = 0, int _flag = 0)
        : x(_x), y(_y), flag(_flag){};
} location;

void dfs(int x, int y, vector<vector<int>>& direct, int m) {
    if (x == 0 && y == 0) {
        cout << "[" << x << "," << y << "]"
             << ",";
        return;
    }
    switch (direct[x][y]) {
        case 1:
            dfs(x - 1, y, direct, m);
            break;
        case 2:
            dfs(x + 1, y, direct, m);
            break;
        case 3:
            dfs(x, y - 1, direct, m);
            break;
        case 4:
            dfs(x, y + 1, direct, m);
            break;
    }
    cout << "[" << x << "," << y << "]";
    if (x == 0 && y == m - 1) {
        cout << endl;
    } else
        cout << ",";
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> map(n);
    vector<vector<int>> dp(n);
    vector<vector<int>> direct(n);
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            map[i].push_back(tmp);
            dp[i].push_back(0x70000000);
            direct[i].push_back(0);
        }
    }
    dp[0][0] = 0;

    queue<location> q;
    q.push((location){0, 0, 0});

    location cur_loc;
    while (!q.empty()) {
        cur_loc = q.front();
        q.pop();

        int x = cur_loc.x;
        int y = cur_loc.y;
        if (x - 1 >= 0 && map[x - 1][y] == 1) {
            if (dp[x - 1][y] != 0x70000000) q.push((location){x - 1, y, 2});
            if (dp[x - 1][y] > dp[x][y] + 3) {
                dp[x - 1][y] = dp[x][y] + 3;
                direct[x - 1][y] = 2;
            }
            // if (find(q.begin(), q.end(), (location){x - 1, y, 2}) ==
            // q.end())
        }
        if (y - 1 >= 0 && map[x][y - 1] == 1) {
            if (dp[x][y - 1] == 0x70000000) q.push((location){x, y - 1, 4});

            if (dp[x][y - 1] > dp[x][y] + 1) {
                dp[x][y - 1] = dp[x][y] + 1;
                direct[x][y - 1] = 4;
            }

            // if (find(q.begin(), q.end(), (location){x, y - 1, 4}) ==
            // q.end())
        }
        if (x + 1 < n && map[x + 1][y] == 1) {
            if (dp[x + 1][y] == 0x70000000) q.push((location){x + 1, y, 1});

            if (dp[x + 1][y] > dp[x][y]) {
                dp[x + 1][y] = dp[x][y];
                direct[x + 1][y] = 1;
            }
            // if (find(q.begin(), q.end(), (location){x + 1, y, 1}) ==
            // q.end())
        }
        if (y + 1 < n && map[x][y + 1] == 1) {
            if (dp[x][y + 1] == 0x70000000) q.push((location){x, y + 1, 3});
            if (dp[x][y + 1] > dp[x][y] + 1) {
                dp[x][y + 1] = dp[x][y] + 1;
                direct[x][y + 1] = 3;
            }

            // if (find(q.begin(), q.end(), (location){x, y + 1, 3}) ==
            // q.end())
        }
    }

    if (dp[0][m - 1] > p) {
        cout << "Can not escape!" << endl;
    } else {
        dfs(0, m - 1, direct, m);
    }
    /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << direct[i][j] << " ";
            }
            cout << endl;
        }
    */
    return 0;
}