#include <iostream>
#include <vector>

using namespace std;

int maxf(int a, int b) { return a > b ? a : b; }

void print_arr(const vector<int> num) {
    for (auto i : num) {
        cout << i << " ";
    }
    cout << endl;
}

// 将数字的低位放在vector中的低位
void intToVec(vector<int>& nums, int i) {
    nums.clear();
    if (i < 0) {
        i = 0 - i;
    }
    while (i) {
        int tmp = i % 10;
        i = i / 10;
        nums.push_back(tmp);
    }
}

class Solution {
   public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (k > len1 + len2) {
            return vector<int>(0);
        }

        vector<int> res;
        vector<vector<int> > bigcom1(len1);
        vector<vector<int> > bigcom2(len2);

        for (int i = 0; i < len1; i++) bigcom1[i] = vector<int>(len1, 0);
        for (int i = 0; i < len2; i++) bigcom2[i] = vector<int>(len2, 0);

        int max = 0x80000000;
        for (int i = 0; i < len1; i++) {
            if (max < nums1[i]) {
                max = nums1[i];
            }
            bigcom1[i][0] = max;  // 到第I个数字找到长度为1的最大值为
        }

        max = 0x80000000;
        for (int i = 0; i < len2; i++) {
            if (max < nums2[i]) {
                max = nums2[i];
            }
            bigcom2[i][0] = max;  // 到第I个数字找到长度为1的最大值为
        }

        for (int j = 1; j < len1; j++) {
            for (int i = j; i < len1; i++) {
                // 当前到长度 i，组成长度为j+1的最长串
                // dp[i][j] = max(dp[i-1][j-1]*10 + num[j], dp[i][j-1]);
                bigcom1[i][j] = maxf(bigcom1[i - 1][j - 1] * 10 + nums1[i],
                                     bigcom1[i - 1][j]);
            }
        }

        for (int j = 1; j < len2; j++) {
            for (int i = j; i < len2; i++) {
                // 当前到长度 j，组成长度为i的最长串
                // dp[i][j] = max(dp[i-1][j-1]*10 + num[j], dp[i][j-1]);
                bigcom2[i][j] = maxf(bigcom2[i - 1][j - 1] * 10 + nums2[i],
                                     bigcom2[i - 1][j]);
            }
        }

        /*
                for (int i = 0; i < len1; i++) {
                    for (int j = 0; j < len1; j++) {
                        cout << bigcom1[i][j] << " ";
                    }
                    cout << endl;
                }

                for (int i = 0; i < len2; i++) {
                    for (int j = 0; j < len2; j++) {
                        cout << bigcom2[i][j] << " ";
                    }
                    cout << endl;
                }
        */
        // 首先判断是否可以只用一边的办法
        vector<int> arr1;
        vector<int> arr2;
        max = 0x80000000;
        if (len1 >= k) {
            if (max < bigcom1[len1 - 1][k - 1]) max = bigcom1[len1 - 1][k - 1];
        }
        if (len2 >= k) {
            if (max < bigcom2[len2 - 1][k - 1]) max = bigcom2[len2 - 1][k - 1];
        }
        for (int i = 0; i < k - 1; i++) {
            int j = k - 2 - i;
            if (len1 > 0) {
                intToVec(arr1, bigcom1[len1 - 1][i]);
                // print_arr(arr1);
            }
            if (len2 > 0) {
                intToVec(arr2, bigcom2[len2 - 1][j]);

                //   print_arr(arr2);
            }
            // cout << "******" << endl;
            int n = arr1.size() - 1;
            int m = arr2.size() - 1;
            int tmpSum = 0;
            while (n >= 0 && m >= 0) {
                if (arr1[n] > arr2[m]) {
                    tmpSum = tmpSum * 10 + arr1[n];
                    n--;
                } else if (arr1[n] < arr2[m]) {
                    tmpSum = tmpSum * 10 + arr2[m];
                    m--;
                } else if (arr1[n] == arr2[m]) {
                    int nn = n;
                    int mm = m;
                    while (nn >= 0 && mm >= 0 && arr1[nn] == arr2[mm]) {
                        nn--;
                        mm--;
                    }
                    if (nn == -1 || mm == -1) {
                        if (nn == -1) {
                            while (n > nn) {
                                tmpSum = tmpSum * 10 + arr1[n];
                                n--;
                            }
                        }
                        if (mm == -1) {
                            while (m > mm) {
                                tmpSum = tmpSum * 10 + arr2[m];
                                m--;
                            }
                        }
                    } else if (arr1[nn] > arr2[mm]) {
                        while (n >= nn) {
                            tmpSum = tmpSum * 10 + arr1[n];
                            n--;
                        }
                    } else if (arr1[nn] < arr2[mm]) {
                        while (m >= mm) {
                            tmpSum = tmpSum * 10 + arr2[m];
                            m--;
                        }
                    }
                }
            }
            while (m >= 0) {
                tmpSum = tmpSum * 10 + arr2[m];
                m--;
            }
            while (n >= 0) {
                tmpSum = tmpSum * 10 + arr1[n];
                n--;
            }
            // cout << tmpSum << endl;
            if (max < tmpSum) {
                max = tmpSum;
            }
        }
        intToVec(res, max);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(void) {
    vector<int> a{3, 4, 6, 5};
    vector<int> b{9, 1, 2, 5, 8, 3};
    Solution s;
    s.maxNumber(a, b, 5);
    return 0;
}