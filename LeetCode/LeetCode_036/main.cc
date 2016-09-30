#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> cube(9);
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                if (row[i].find(board[i][j]) == row[i].end()) {
                    row[i].insert(board[i][j]);
                } else
                    return false;
                if (col[j].find(board[i][j]) == col[j].end()) {
                    col[j].insert(board[i][j]);
                } else
                    return false;
                int cnum = (j / 3) + (i / 3) * 3;
                if (cube[cnum].find(board[i][j]) == cube[cnum].end()) {
                    cube[cnum].insert(board[i][j]);
                } else
                    return false;
            }
        }
        return true;
    }
};