#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int case_num;
    cin >> case_num;
    string input_str;
    vector<int> money;
    vector<int> *dp0[2];
    vector<int> *dp1[2];
    while (case_num--) {
        money.clear();
        cin >> input_str;
        int loc = 0;
        int i;
        for (i = 0; i < input_str.size(); i++) {
            if (input_str[i] == ',') {
                money.push_back(stoi(input_str.substr(loc, i - loc)));
                loc = i + 1;
            } else if (input_str[i] == ' ') {
                loc = i;
            }
        }
        if (loc - i != 0) {
            money.push_back(stoi(input_str.substr(loc, i - loc)));
        }
        dp0[0] = new vector<int>(money.size() + 1, 0);
        dp0[1] = new vector<int>(money.size() + 1, 0);
        dp1[0] = new vector<int>(money.size() + 1, 0);
        dp1[1] = new vector<int>(money.size() + 1, 0);

        (*dp0[0])[0] = 0;
        (*dp0[1])[0] = money[0];
        (*dp1[0])[1] = 0;
        (*dp1[1])[1] = money[1];

        for (int i = 2; i < money.size(); i++) {
            (*dp1[0])[i] = max((*dp1[0])[i - 1], (*dp1[1])[i - 1]);
            (*dp1[1])[i] = (*dp1[0])[i - 1] + money[i];
        }
        for (int i = 1; i < money.size() - 1; i++) {
            (*dp0[0])[i] = max((*dp0[0])[i - 1], (*dp0[1])[i - 1]);
            (*dp0[1])[i] = (*dp0[0])[i - 1] + money[i];
        }
        int res0 =
            max((*dp0[0])[money.size() - 2], (*dp0[1])[money.size() - 2]);
        int res1 =
            max((*dp1[0])[money.size() - 1], (*dp1[1])[money.size() - 1]);

        cout << max(res0, res1) << endl;

        delete dp0[0];
        delete dp0[1];
        delete dp1[0];
        delete dp1[1];
    }
}