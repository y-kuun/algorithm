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
    int min = 0x0;
    int b = 0;
    int s = 0;
    int low = 0;
    for (int i = 1; i < n; i++) {
        if (vec[i] <= vec[low]) {
            low = i;
        }
        if (vec[i] - vec[low] > min) {
            min = vec[i] - vec[low];
            b = low;
            s = i;
        }
        if (vec[i] - vec[low] == min) {
            if (low > b) b = low;
            if (s < low)
                s = i;
            else if (s < low && i < s)
                s = i;
        }
    }
    if (min != 0)
        cout << b << "," << s << endl;
    else if (min == 0)
        cout << "-1,-1" << endl;
    return 0;
}