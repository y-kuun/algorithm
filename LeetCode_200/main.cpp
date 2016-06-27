#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
    void vis(int i, int j, const vector<vector<char>> &grid);
    vector<vector<bool>> vm;
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++){
            vm.push_back(vector<bool>(grid[i].size()));
            for(int j = 0; j < grid[i].size(); j++){
                    vm[i].push_back(bool(false));
                }
            }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1' && vm[i][j] == false){
                    vis( i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

void Solution::vis(int i, int j, const vector<vector<char>> &grid){
    queue<int> q;
    q.push(i);
    q.push(j);
    vm[i][j] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        if(x - 1 >= 0 && grid[x-1][y] == '1' && vm[x-1][y] == false){
            q.push(x-1);
            q.push(y);
            vm[x-1][y] == true;
        }
        if(x + 1 < grid.size() && grid[x+1][y] == '1' && vm[x+1][y] == false){
            q.push(x+1);
            q.push(y);
            vm[x+1][y] == true;
        }
        if(y - 1 >= 0 && grid[x][y-1] == '1' && vm[x][y-1] == false){
            q.push(x);
            q.push(y-1);
            vm[x][y-1] == true;
        }
        if(y + 1 < grid[x].size() && grid[x][y+1] == '1' && vm[x][y+1] == false){
            q.push(x);
            q.push(y+1);
            vm[x][y+1] == true;
        }
    }
}
