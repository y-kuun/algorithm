#include <vector>

using namespace std;
/*
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
*/

class Solution {
   public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int replace = matrix[i][j];
                cout << replace << " " << i << " " << j << endl;
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = replace;
            }
        }
    }
};