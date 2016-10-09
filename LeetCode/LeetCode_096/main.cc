
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int numTrees(int n) {
        int a = 1;
        int b = 2;
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> vec(n + 1, 0);
        vec[0] = 1;
        vec[1] = 1;
        vec[2] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += vec[j] * vec[i - 1 - j];
            }
            vec[i] = sum;
        }
        return vec[n];
    }
};