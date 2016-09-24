#include <cmath>
#include <iostream>
#include <unordered_set>

using namespace std;

bool is_str(string str) {
    int len = str.size();
    if (len % 2 != 0) {
        return false;
    }
    int i = 0;
    int j = (len / 2);
    while (j != len) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j++;
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    int cnt = 0;
    int len = str.size();
    unordered_set<string> st;

    for (int i = 0; i < len; i++) {
        for (int j = 1; j + i <= len; j++) {
            string tmp_str = str.substr(i, j);
            if (is_str(tmp_str)) {
                if (st.find(tmp_str) == st.end()) {
                    st.insert(tmp_str);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}