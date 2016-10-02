#include <utility>
#include <vector>


using namespace std;

class Solution {
   public:
    void setZero(vector<vector<int> >& matrix, int x, int y) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][y] = 0;
        }
        for (int i = 0; i < matrix[x].size(); i++) {
            matrix[x][i] = 0;
        }
    }
    void setZeroes(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int> > zero;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zero.push_back(pair<int, int>{i, j});
                }
            }
        }
        for (int i = 0; i < zero.size(); i++) {
            int x = zero[i].first;
            int y = zero[i].second;
            setZero(matrix, x, y);
        }
    }
};