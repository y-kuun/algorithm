#include <vector>

using namespace std;

// 1 2 3 5 4 3 2 1 3 6 7 2

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int res = 0;
        int n = ratings.size();
        vector<int> cndy(n, 0);
        int prev;
        int tmp0, tmp1;
        // 先从左到右 进行 升序查找，
        // 再从右到左 进行 升序查找。
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                if (prev == -1) {
                    prev = i - 1;
                    cndy[prev] = 1;
                }
                cndy[i] = max(cndy[i], i - prev + 1);
            } else if (i == 0 && ratings[i] < ratings[i + 1]) {
                cndy[i] = 1;
                prev = 0;
            } else if (ratings[i] == ratings[i - 1]) {
                prev = i;
                cndy[prev] = max(cndy[prev], 1);
            } else {
                prev = -1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                if (prev == -1) {
                    prev = i + 1;
                    cndy[prev] = 1;
                }
                cndy[i] = max(cndy[i], prev - i + 1);
            } else if (i == n - 1 && ratings[i] < ratings[i - 1]) {
                cndy[i] = 1;
                prev = n - 1;
            } else if (ratings[i] == ratings[i + 1]) {
                prev = i;
                cndy[prev] = max(cndy[prev], 1);
            } else {
                prev = -1;
            }
        }
        for (auto i : cndy) {
            // cout << i << " ";
            res += i;
        }
        // cout << endl;
        return res;
    }
};

/* TLE
class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
            if (ratings[i] < ratings[i - 1] && candy[i] >= candy[i - 1]) {
                candy[i] = candy[i - 1] - 1;
            } else if (ratings[i] == ratings[i - 1]) {
            }
        }
        for (int i = 0; i < n; i++) {
            if (candy[i] < 1) {
                candy[i] = 1;
                int k = i - 1;
                while (k >= 0) {
                    if (ratings[k] < ratings[k + 1] &&
                        candy[k] >= candy[k + 1]) {
                        candy[k] = candy[k + 1] - 1;
                        k--;
                    } else if (ratings[k] > ratings[k + 1] &&
                               candy[k] <= candy[k + 1]) {
                        candy[k] = candy[k + 1] + 1;
                        k--;
                    } else
                        break;
                }
                k = i + 1;
                while (k < n) {
                    if (ratings[k] < ratings[k - 1] &&
                        candy[k] >= candy[k - 1]) {
                        candy[k] = candy[k - 1] - 1;
                        k++;
                    } else if (ratings[k] > ratings[k - 1] &&
                               candy[k] <= candy[k - 1]) {
                        candy[k] = candy[k - 1] + 1;
                        k++;
                    } else
                        break;
                }
            }
        }
        int res = 0;
        for (auto i : candy) {
            res += i;
        }
        return res;
    }
};
*/