#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>*> map(n + 1);
    for (int i = 0; i < map.size(); i++) {
        map[i] = new vector<int>(n + 1, 0);
    }
    int i = 1;
    int x = 1;
    int y = 1;
    int time = n;
    int k = time;
    int flag = 0;
    while (i <= n * n) {
        while (k--) {
            (*map[x])[y] = i++;
            if (k != 0) {
                switch (flag) {
                    case 0:
                        y++;
                        break;
                    case 1:
                        x++;
                        break;
                    case 2:
                        y--;
                        break;
                    case 3:
                        x--;
                        break;
                }
            }
        }
        flag = (flag + 1) % 4;
        switch (flag) {
            case 0:
                time = time - 2;
                k = time;
                y++;
                break;
            case 1:
                k = time - 1;
                x++;
                break;
            case 2:
                k = time - 1;
                y--;
                break;
            case 3:
                k = time - 2;
                x--;
                break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (*map[i])[j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < map.size(); i++) {
        delete map[i];
    }
    return 0;
}