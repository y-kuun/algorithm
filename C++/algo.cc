#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    vector<int> arr;
    int tmp;
    while (cin >> tmp) {
        arr.push_back(tmp);
    }
    int len = arr.size();

    vector<int> dp(arr[len - 1] + 1, 0);

    for (int i = 0; i <= arr[len - 1]; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] <= i && dp[i] > arr[i - arr[j]]) {
                if (dp[i] == 0)
                    dp[i] = arr[i - arr[j]] + 1;
                else if (dp[i] > arr[i - arr[j]])
                    dp[i] = arr[i - arr[j]] + 1;
            }
        }
    }

    if(dp])
    cout << dp[arr[len - 1]] << endl;

    return 0;
}