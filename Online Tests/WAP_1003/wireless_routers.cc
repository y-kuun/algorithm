#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int n, m;
    cin >> n >> m;

    vector<int> room_point(n);
    vector<vector<int> > room_map(n);

    for (auto& i : room_map) {
        i = vector<int>(n, 0);
    }

    for (int i = 0; i < n; i++) {
        cin >> room_point[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        room_map[x][y] = room_map[y][x] = 1;
    }

    return 0;
}
