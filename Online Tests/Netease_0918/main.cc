#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool dfs(int x, int y, vector<vector<int>>& map, int flag) {
    bool resflag = false;
    map[x][y] = flag;
    int tx, ty;
    tx = x + 1;
    ty = y;
    while (map[tx][ty] != flag && tx < 8) {
        tx++;
    }
    for (int i = x + 1; map[i][ty] == 0 - flag && tx < 8 && map[tx][ty] == flag;
         i++) {
        resflag = true;
        map[i][ty] = flag;
    }
    tx = x - 1;
    ty = y;
    while (map[tx][ty] != flag && tx >= 0) {
        tx--;
    }
    for (int i = x - 1;
         map[i][ty] == 0 - flag && tx >= 0 && map[tx][ty] == flag; i--) {
        resflag = true;
        map[i][ty] = flag;
    }
    ty = y + 1;
    tx = x;
    while (map[tx][ty] != flag && ty < 8) {
        ty++;
    }
    for (int i = y + 1; map[tx][i] == 0 - flag && ty < 8 && map[tx][ty] == flag;
         i++) {
        resflag = true;
        map[tx][i] = flag;
    }
    ty = y - 1;
    tx = x;
    while (map[tx][ty] != flag && ty >= 0) {
        ty--;
    }
    for (int i = y - 1;
         map[tx][i] == 0 - flag && ty >= 0 && map[tx][ty] == flag; i--) {
        resflag = true;
        map[tx][i] = flag;
    }
    ty = y - 1;
    tx = x - 1;
    while (map[tx][ty] != flag && ty >= 0 && tx >= 0) {
        ty--;
        tx--;
    }
    for (int i = x - 1, j = y - 1;
         map[i][j] == 0 - flag && tx >= 0 && ty >= 0 && map[tx][ty] == flag;
         i--, j--) {
        resflag = true;
        map[i][j] = flag;
    }
    ty = y + 1;
    tx = x + 1;
    while (map[tx][ty] != flag && ty < 8 && tx < 8) {
        ty++;
        tx++;
    }
    for (int i = x + 1, j = y + 1;
         map[i][j] == 0 - flag && tx < 8 && ty < 8 && map[tx][ty] == flag;
         i++, j++) {
        resflag = true;
        map[i][j] = flag;
    }
    ty = y + 1;
    tx = x - 1;
    while (map[tx][ty] != flag && ty < 8 && tx >= 0) {
        ty++;
        tx--;
    }
    for (int i = x - 1, j = y + 1;
         map[i][j] == 0 - flag && tx >= 0 && ty >= 0 && map[tx][ty] == flag;
         i--, j++) {
        resflag = true;
        map[i][j] = flag;
    }
    ty = y - 1;
    tx = x + 1;
    while (map[tx][ty] != flag && tx < 8 && ty >= 0) {
        ty--;
        tx++;
    }
    for (int i = x + 1, j = y - 1;
         map[i][j] == 0 - flag && tx < 8 && ty >= 0 && map[tx][ty] == flag;
         i++, j--) {
        resflag = true;
        map[i][j] = flag;
    }
    return resflag;
}

int main(int argc, char** argv) {
    int case_num;
    char ch;
    cin >> case_num;
    vector<vector<int>> map(8);
    while (case_num--) {
        int x, y, flag;
        for (int i = 0; i < 8; i++) {
            map[i].clear();
            for (int j = 0; j < 8; j++) {
                cin >> ch;
                if (ch == '.') map[i].push_back(0);
                if (ch == '*') {
                    map[i].push_back(-1);
                }
                if (ch == 'o') {
                    map[i].push_back(1);
                }
            }
        }
        int k;
        int bnum = 0;
        int wnum = 0;

        cin >> k;
        while (k--) {
            cin >> x >> y >> flag;
            flag = flag == 0 ? -1 : 1;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }
            dfs(x, y, map, flag);
            int resflag = true;
            while (resflag) {
                resflag = false;
                for (int i = 0; i < 8 && resflag; i++) {
                    for (int j = 0; j < 8 && resflag; j++) {
                        if (map[i][j] == flag) {
                            resflag = dfs(x, y, map, flag);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (map[i][j] == -1) {
                    bnum++;
                } else if (map[i][j] == 1) {
                    wnum++;
                }
            }
        }
        cout << bnum << " " << wnum << endl;
    }
    return 0;
}