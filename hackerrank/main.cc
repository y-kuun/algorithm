#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int max = 0;
    int base = 1;
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        int tmp = n & (base << i);
        if (tmp != 0) {
            cnt++;
        } else if (tmp == 0) {
            if (cnt > max) {
                max = cnt;
            }
            cnt = 0;
        }
    }
    int* a = NULL;
    a[100] = 10;
    cout << a[100] << endl;
    cout << max << endl;
    return 0;
}
