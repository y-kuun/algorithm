#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int max = 0x80000000;
    int low;
    int high;
    string ans;
    vector<int> ipt;
    int case_num;
    cin >> case_num;
    vector<vector<int> > map(case_num);
    for (int i = 0; i < case_num; i++) {
        int hloc = 0;
        int loc = 0;
        cin >> ans;
        ans = ans + ",";
        while (loc < ans.size()) {
            if (ans[loc] == ',') {
                map[i].push_back(stoi(ans.substr(hloc, loc - hloc)));
                hloc = loc + 1;
            }
            while (hloc < ans.size() && (ans[hloc] < '0' || ans[hloc] > '9')) {
                hloc++;
            }
            loc++;
        }
    }
    set<int> st;
    int sum = 0;
    while (st.size() != case_num) {
        int min = 0x70000000;
        int mini = 0;
        int minj = 0;
        for (int i = 0; i < case_num; i++) {
            for (int j = i + 1; j < case_num; j++) {
                if (min > map[i][j]) {
                    min = map[i][j];
                    mini = i;
                    minj = j;
                }
            }
        }
        bool flag = false;
        if (st.find(mini) == st.end()) {
            st.insert(mini);
            flag = true;
        }
        if (st.find(minj) == st.end()) {
            st.insert(minj);
            flag = true;
        }
        if (flag) sum += map[mini][minj];
        map[mini][minj] = 0x70000000;
    }
    cout << sum << endl;
}
