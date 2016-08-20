// error state!
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>

using namespace std;

// 9*81 = 729
// 81 + 81 + 81 + 81 =  324

const int SIZE = 10;
const int CN = 325;
const int RN = 730;

typedef struct dancing_node{
    struct dancing_node *up,*down,*left,*right;
    int x;
    int y;
}dnode;

dnode head[CN];         // 存放十字链表的所有头节点，head[0]代表所有的头节点，head1...CN-1 代表每一列的头节点
int ccount[CN];         // 存放十字链表的每一列的存在节点的计数
int matrix[RN][CN];     // 存放扩展数独问题后的01矩阵
dnode node[RN*CN];      // 针对所有01矩阵中的节点构造一个交叉链表
int id[RN][CN];         // 统计交叉链表中的元素的本来的x，y坐标
int ans[10][10];        // 存储结果

void init_sudoku(){
    memset(head, 0, sizeof(head));
    memset(ccount, 0, sizeof(ccount));
    memset(matrix, 0, sizeof(matrix));
    memset(node, 0, sizeof(node));
    memset(id, 0, sizeof(id));
    memset(ans, 0, sizeof(ans));
}


int set_matrix(int x, int y, int value){

    // 数独当中的第几个格子
    int id = (x - 1) * 9 + y;
    // 根据盒子中的内容判断是第几个解
    int pid = (id - 1) * 9 + value;
    // 每一行存在
    matrix[pid][(x - 1) * 9 + value] = 1;
    // 每一列存在
    matrix[pid][81 + (y - 1) * 9 + value]  = 1;
    // 每一个小九宫格存在
    int t = ((x - 1)/3 * 3 + (y - 1) / 3) + 1;
    matrix[pid][162 + (t - 1)*9 + value]  = 1;

    // 每一个格子当中有数
    matrix[pid][243 + id]  = 1;
}


void build_dancing_matrix(dnode *head){
    // initial the head node of the cross linked list
    head[0].up = head[0].down = head[0].left = head[0].right = head;
    head[0].x = head[0].y = 0;

    dnode *ptmp;
    dnode *ppre = head;
    // init the head node list
    for(int i = 1; i < CN; i++){
        ptmp = &head[i];
        ptmp->x = 0;
        ptmp->y = i;
        ptmp->up = ptmp;
        ptmp->down = ptmp;

        ptmp->left = ppre;
        ptmp->right = ppre->right;
        ppre->right->left = ptmp;
        ppre->right = ptmp;

        ppre = ptmp;
    }

    // 为节点进行编号以及初始化
    // 编号从1开始
    // 为所有存在的节点进行编号
    int cnt = 0;
    for(int i = 1; i < RN; i++){
        for(int j = 1; j < CN; j++){
            if(matrix[i][j] == 1){
                cnt++;
                id[i][j] = cnt;
                node[cnt].left = node[cnt].right = node[cnt].up = node[cnt].down = &node[cnt];
                node[cnt].x = i;
                node[cnt].y = j;
            }
        }
    }

    //cout<<cnt<<endl;

    // 先从列开始构建十字循环矩阵
    // for columns
    for(int j = 1; j < CN; j++){
        ppre = &head[j];
        for(int i = 1; i < RN; i++){
            if(matrix[i][j] == 1){
                ptmp = &node[id[i][j]];

                ccount[j]++;
                ptmp->up = ppre;
                ptmp->down = ppre->down;
                ppre->down->up = ptmp;
                ppre->down = ptmp;

                ppre = ptmp;
            }
        }
    }

    // 已经完成从列开始的构建，现在开始横向构建十字链表
    // for rows
    for(int i = 1; i < RN; i++){
        ppre = NULL;
        for(int j = 1; j < CN; j++){
            if(matrix[i][j] == 1){
                if(ppre == NULL){
                    // 如果是每一行的第一个进行初始化ppre
                    // 由于所有的节点均已经完成初始化，这里并不需要对ppre进行初始化！
                    ppre = &node[id[i][j]];
                } else {
                    ptmp = &node[id[i][j]];
                    ptmp->left = ppre;
                    ptmp->right = ppre->right;
                    ppre->right->left = ptmp;
                    ppre->right = ptmp;

                    ppre = ptmp;
                }
            }
        }
    }
}

void remove(int col){
    dnode *ppre = &head[col];
    ppre->right->left = ppre->left;
    ppre->left->right = ppre->right;
    dnode *ppre2 = ppre->down;
    while(ppre2 != ppre){
        // 由于每一列只能够存在只能够存在一个元素，如果从这一列开始其他相关的行都需要进行删除
        dnode *ppre3 = ppre2->right;
        while(ppre3 != ppre2){
            // 删除在这一列存在元素的其他行
            ccount[ppre3->y] = ccount[ppre3->y] - 1;
            ppre3->down->up = ppre3->up;
            ppre3->up->down = ppre3->down;
            ppre3 = ppre3->right;
        }
        ppre2 = ppre2->down;
    }
}

void resume(int col){
    dnode *ppre = &head[col];
    ppre->right->left = ppre;
    ppre->left->right = ppre;
    dnode *ppre2 = ppre->down;
    while(ppre2 != ppre){
        dnode *ppre3 = ppre2->right;
        while(ppre3 != ppre2){
            ccount[ppre3->y] = ccount[ppre3->y] + 1;
            ppre3->down->up == ppre3;
            ppre3->up->down == ppre3;

            ppre3 = ppre3->right;
        }
        ppre2 = ppre2->down;
    }
}


dnode* findmin(dnode *head){
    // 寻找现存的列的最小值
    int min = INT_MAX;
    dnode *pnode = head->right;
    dnode *pmin;
    while(pnode != head){
        if(min > ccount[pnode->y]){
            min = ccount[pnode->y];
            pmin = pnode;
        }
        pnode = pnode->right;
    }
    return pmin;
}


bool dance(int depth){

    if(head->right == head)
        return true;

    dnode *ppre = findmin(head);
    dnode *ppre2 = ppre->down;
    // 如果出现下面if的情况表明，存在列不能覆盖
    if(ppre2 == ppre)
        return false;

    // 移除当前的这一列，以及所有的在这一列存在元素的冲突行
    remove(ppre->y);
    while(ppre2 != ppre){

        // 由于现在ppre2指向被删除的列的第一个元素
        // 现在开始便利，悬着ppre2当前指向元素存在的行，并且删除与之有共有元素的列。

            //cout<<depth<<endl;
        //cout<<(ppre2->x - 1) / 81 + 1<<"  "<<((ppre2->x - 1) / 9) % 9 + 1<<"  "<<(ppre2->x - 1) % 9 + 1<<endl;


        dnode *ppre3 = ppre2->right;
        while(ppre3 != ppre2){
            remove(ppre3->y);
            ppre3 = ppre3->right;
        }

        if(dance(depth + 1)){
            ans[(ppre2->x - 1) / 81 + 1][(ppre2->x - 1) / 9 % 9 + 1] = (ppre2->x -1) % 9 + 1;
            return true;
        }

        // resume
        ppre3 = ppre2->right;
        while(ppre3 != ppre2){
            resume(ppre3->y);
            ppre3 = ppre3->right;
        }

        ppre2 = ppre2->down;
    }
    resume(ppre->y);
    return false;
}

int main(int argc, char** argv){
    freopen( "input", "r", stdin);
    int case_num;
    int input_int;
    scanf("%d",&case_num);
    while(case_num--){
        init_sudoku();
     //   int m = 0;
        for(int i = 1; i < SIZE; i++ ){
            for(int j = 1; j < SIZE; j++){
                scanf("%u", &input_int);
                if(input_int == 0){
    //                m++;
                    for(int k = 1; k < SIZE; k++){
                        set_matrix(i, j, k);
                    }
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = input_int;
                    set_matrix(i, j, input_int);
                }
            }
        }
        //cout<<m<<endl;
        build_dancing_matrix(head);
        dance(0);

        for(int i = 1; i < SIZE; i++){
            for(int j = 1; j < SIZE; j++){
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
