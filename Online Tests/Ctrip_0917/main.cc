#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int max = 0x80000000;
    int low;
    int high;
    string ans;
    vector<int> ipt;
    cin >> ans;
    ans = ans + ",";
    int hloc = 0;
    int loc = 0;
    while (loc < ans.size()) {
        if (ans[loc] == ',') {
            ipt.push_back(stoi(ans.substr(hloc, loc - hloc)));
            hloc = loc + 1;
        }
        while (hloc < ans.size() && (ans[hloc] < '0' || ans[hloc] > '9')) {
            hloc++;
        }
        loc++;
    }
    low = 0;
    high = 0;
    for (int i = 1; i < ipt.size(); i++) {
        if (ipt[i] > ipt[high]) {
            high = i;
        }
        if (max < ipt[high] - ipt[low]) {
            max = ipt[high] - ipt[low];
        }
        if (ipt[i] < ipt[low]) {
            low = i;
            high = i;
        }
    }
    if (max < ipt[high] - ipt[low]) {
        max = ipt[high] - ipt[low];
    }
    cout << max << endl;
}