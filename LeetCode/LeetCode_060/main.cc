#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int func(int k) {
    int sum = 1;
    for (int i = 1; i <= k; i++) {
        sum = sum * i;
    }
    return sum;
}

void swap(string& s, int i, int j) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

class Solution {
   public:
    string getPermutation(int n, int k) {
        string s = "123456789";
        k = k - 1;
        for (int i = 0; k != 0 && i < n; i++) {
            int tmp = func(n - 1 - i);
            int loc = k / tmp;
            if (loc != 0) {
                swap(s, i, i + loc);
                k = k % tmp;
                sort(s.begin() + i + 1, s.begin() + n);
            }
        }
        return s.substr(0, n);
    }
};

int main() {
    Solution s;
    s.getPermutation(3, 5);
    return 0;
}