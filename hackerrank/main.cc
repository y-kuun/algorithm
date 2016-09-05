#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int case_num;
    vector<vector<char> > *map;

    cin >> case_num;
    while (case_num--) {
        int n;
        cin >> n;
        char ch;
        int flag = true;
        string str;
        map = new vector<vector<char> >(n);
        for (int j = 0; j < n; j++) {
            cin >> str;
            for (int i = 0; i < n; i++) {
                (*map)[j].push_back(str[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            sort((*map)[i].begin(), (*map)[i].end());
        }

        for (int i = 0; i < n - 1 && flag; i++) {
            for (int j = 0; j < n && flag; j++) {
                if ((*map)[i][j] > (*map)[i + 1][j]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    delete map;

    return 0;
}
