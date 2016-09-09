#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rs;
int cs;
char** vm;
char** grd;


void dfs(int x, int y){
    vm[x][y] = 1;
    if(x - 1 >= 0 && grd[x-1][y] == '1' && vm[x-1][y] == 0){
        dfs(x-1, y);
    }
    if(x + 1 < rs && grd[x+1][y] == '1' && vm[x+1][y] == 0){
        dfs(x+1, y);
    }
    if(y - 1 >= 0 && grd[x][y-1] == '1' && vm[x][y-1] == 0){
        dfs(x, y-1);
    }
    if(y + 1 < cs && grd[x][y+1] == '1' && vm[x][y+1] == 0){
        dfs(x, y+1);
    }
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    rs = gridRowSize;
    cs = gridColSize;
    grd = grid;
    int cnt = 0;
    vm = (char**)malloc(gridRowSize * sizeof(char*));
    for(int i = 0; i < gridRowSize; i++){
        vm[i] = (char*)malloc(gridColSize * sizeof(char));
    }
    for(int i = 0; i < gridRowSize; i++)
        for(int j = 0; j < gridColSize; j++)
            vm[i][j] = 0;
    for(int i = 0; i < gridRowSize; i++){
        for(int j = 0; j < gridColSize; j++){
            if(grid[i][j] == '1' && vm[i][j] == 0){
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

