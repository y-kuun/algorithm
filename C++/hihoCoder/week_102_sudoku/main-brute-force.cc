#include <iostream>
#include <queue>
#include <bitset>
#include <cstring>
#include <cstdio>
using namespace std;

typedef unsigned char UINT8;


class sudoku{
    public:
        queue<UINT8> slot_queue;       // partern as x,y,x,y
        static bool is_over;
        static const int SIZE = 10;
        sudoku();
        void clean();
        void initSudokuSet(int x, int y, int value);
        UINT8 getZone(int x, int y);
        void sudokuToString();
        void retrival_sudoku(int x, int y, int value);
        UINT8 sudoku_map[SIZE][SIZE];
        bitset<SIZE> row[SIZE];
        bitset<SIZE> column[SIZE];
        bitset<SIZE> zone[SIZE];
};

void sudoku::sudokuToString(){
    for(int i = 1; i < this->SIZE; i++){
        for(int j = 1; j < this->SIZE; j++){
            printf("%d ",this->sudoku_map[i][j]);
        }
        cout<<endl;
    }
}

bool sudoku::is_over = false;

void sudoku::clean(){
    sudoku::is_over = false;
    for(int i = 0; i < this->SIZE; i++){
        this->row[i].reset();
        this->column[i].reset();
        this->zone[i].reset();
    }
    // clear the sudoku_map
    memset(this->sudoku_map, 0, sizeof(this->sudoku_map));
    // clear the empty slot
    while(!slot_queue.empty())
        this->slot_queue.pop();
}

sudoku::sudoku(){
    // clear all the related sudoku relevant bitsets
    this->clean();
}

void sudoku::retrival_sudoku(int x, int y, int value){
    this->row[x].reset(value);
    this->column[y].reset(value);
    this->zone[getZone(x, y)].reset(value);
    this->sudoku_map[x][y] = 0;
}

void sudoku::initSudokuSet(int x, int y, int value){
    if(value){
        this->row[x].set(value);
        this->column[y].set(value);
        this->zone[getZone(x, y)].set(value);
    }else if(value == 0){
        this->slot_queue.push(x);
        this->slot_queue.push(y);
    }
    this->sudoku_map[x][y] = value;
}

UINT8 sudoku::getZone(int x, int y)
{
    if(x >= 1 && x <= 3){
        if(y >= 1 && y <= 3)
            return 1;
        if(y >= 4 && y <= 6)
            return 2;
        if(y >= 7 && y <= 9)
            return 3;
    }else if(x >= 4 && x <= 6){
        if(y >= 1 && y <= 3)
            return 4;
        if(y >= 4 && y <= 6)
            return 5;
        if(y >= 7 && y <= 9)
            return 6;
    }else if(x >= 7 && x <= 9){
        if(y >= 1 && y <= 3)
            return 7;
        if(y >= 4 && y <= 6)
            return 8;
        if(y >= 7 && y <= 9)
            return 9;
    }
}

void dosudoku(sudoku sdk){
    int x,y;
    bitset<sudoku::SIZE> current_situation;
    if(!sdk.slot_queue.empty() && !sudoku::is_over){
        x = sdk.slot_queue.front();
        sdk.slot_queue.pop();
        y = sdk.slot_queue.front();
        sdk.slot_queue.pop();
        current_situation = sdk.row[x] | sdk.column[y] | sdk.zone[sdk.getZone(x,y)];
        // cout<<sdk.slot_queue.size()<<" "<<x<<" "<<y<<" "<<current_situation.size()-current_situation.count() - 1<<endl;
        for(int i = 1; i < sudoku::SIZE; i++){
            if(!current_situation.test(i)){
                sdk.initSudokuSet(x, y, i);
                dosudoku(sdk);
                sdk.retrival_sudoku(x, y, i);
            }
        }
    }else if(sdk.slot_queue.empty() && !sudoku::is_over){
        sudoku::is_over = true;
        sdk.sudokuToString();
    }
}


int main(int argc, char** argv){
    int case_num;
    int x,y;
    int input_int;
    sudoku sdk;
    cin>>case_num;
    while(case_num--){
        for(int i = 1; i < sudoku::SIZE; i++ ){
            for(int j = 1; j < sudoku::SIZE; j++){
                scanf("%u", &input_int);
                sdk.initSudokuSet(i, j, input_int);
            }
        }
        dosudoku(sdk);
        sdk.clean();
    }
    return 0;
}
