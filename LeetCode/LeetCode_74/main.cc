#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n - 1;
        while (matrix[x][y] != target) {
            while (x < m && matrix[x][y] < target) {
                x++;
            }
            if (x == m)
                return false;
            return binary_search(matrix[x].begin(), matrix[x].end(), target);
        }
        return true;
    }
};