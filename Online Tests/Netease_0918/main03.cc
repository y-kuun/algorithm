#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int case_num;
    int n, l;
    int tmp;
    vector<int> vec;
    set<int> s;
    cin >> case_num;
    while (case_num--) {
        cin >> n >> l;
        vec.clear();
        for (int i = 0; i < l; i++) {
            cin >> tmp;
            vec.push_back(tmp);
        }

        bool flag = false;
        int i = 0;
        for (int j = 0; j <= n && !flag; j++) {
            flag = true;
            s.clear();

            for (int k = 0; k < j; k++) {
                s.insert(vec[i + k]);
            }
            if (s.size() == j) {
                s.clear();
                int cnt = 0;
                for (int m = i + j; m < l; m++) {
                    s.insert(vec[m]);
                    cnt++;
                    if (cnt == n) {
                        if (s.size() != n) {
                            flag = false;
                            break;
                        } else {
                            cnt = 0;
                            s.clear();
                        }
                    }
                }
                if (s.size() != cnt) {
                    flag = false;
                }
            } else
                flag = false;
        }
        if (flag) {
            cout << "CAN'T DECIDE" << endl;
        } else
            cout << "B" << endl;
    }
    return 0;
}
