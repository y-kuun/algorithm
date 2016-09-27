#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void swap(string& str, int i, int j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

set<string> rs;

void permu(string str, int left) {
    if (left == str.size() - 1) {
        // cout << str << endl;
        rs.insert(str);
        return;
    }
    permu(str, left + 1);
    for (int i = left + 1; i < str.size(); i++) {
        swap(str, left, i);
        permu(str, left + 1);
        swap(str, left, i);
    }
}

int main(int argc, char** argv) {
    freopen("input", "r+", stdin);
    string str;
    cin >> str;
    permu(str, 0);

    for (auto i : rs) {
        cout << i << endl;
    }

    return 0;
}