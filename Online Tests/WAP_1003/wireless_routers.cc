// Exam2 Wireless ROuters
// Author:  Yukun Du
// Date:    2010-10-03
// Description: all the N room with N-1 door can be regarded as a binary tree

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
struct treeNode {
    int id;
    int point;
    struct treeNode *left;
    struct treeNode *right;
    treeNode(int _id = 0, int _point = 0)
        : id(_id), point(_point), left(NULL), right(NULL){};
};

using TreeNode_p = struct treeNode *;
*/

int dp[3][1001][101] = {0};  // for the tree dp
int n, m;

void walker(int cur_id, vector<vector<int>> &room_map,
            const vector<int> &room_point) {
    if (cur_id == -1) {
        return;
    }
    int room_num = room_point.size();
    int left = -1;
    int right = -1;
    for (int i = 0; i < room_num; i++) {
        if (room_map[cur_id][i] == 1) {
            room_map[cur_id][i] = room_map[i][cur_id] = 0;
            if (left == -1) {
                left = i;
            } else
                right = i;
        }
    }
    walker(left, room_map, room_point);
    walker(right, room_map, room_point);

    if (left == -1 && right == -1) {
        for (int i = 1; i <= m; i++) {
            dp[cur_id][1][2] = room_point[cur_id];
        }
        return;
    }

    // 不选当前节点
    for (int i = 0; i <= m; i++) {
        int sum = 0;
        int lval;
        int rval;
        for (int j = 0; j <= i; j++) {
            if (left != -1)
                lval = dp[left][j][0];
            else
                lval = 0;
            if (right != -1)
                rval = dp[right][m - j][0];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
        }
        dp[cur_id][i][0] = sum;
    }
    // 不选当前节点但是被覆盖
    for (int i = 0; i <= m; i++) {
        int sum = 0;
        int lval;
        int rval;
        for (int j = 0; j <= i; j++) {
            // 两个子节点都选
            if (left != -1)
                lval = dp[left][j][1];
            else
                lval = 0;
            if (right != -1)
                rval = dp[left][m - j][1];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
            // pick right
            if (left != -1)
                lval = dp[left][j][0];
            else
                lval = 0;
            if (right != -1)
                rval = dp[left][m - j][1];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
            // pick left
            if (left != -1)
                lval = dp[left][j][1];
            else
                lval = 0;
            if (right != -1)
                rval = dp[left][m - j][0];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
        }
        dp[cur_id][i][1] = sum + room_point[cur_id];
    }
    // pick the current one;
    for (int i = 0; i <= m; i++) {
        int sum = 0;
        int lval;
        int rval;
        for (int j = 0; j < i; j++) {
            // 两个子节点都选
            if (left != -1)
                lval = dp[left][j][1];
            else
                lval = 0;
            if (right != -1)
                rval = dp[left][m - j][1];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
            // pick right
            if (left != -1)
                lval = dp[left][j][0];
            else
                lval = 0;
            if (right != -1)
                rval = dp[left][m - j][1];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
            // pick left
            if (left != -1)
                lval = dp[left][j][1];
            else
                lval = 0;
            if (right != -1)
                rval = dp[left][m - j][0];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
            // pick none
            if (left != -1)
                lval = dp[left][j][0];
            else
                lval = 0;
            if (right != -1)
                rval = dp[left][m - j][0];
            else
                rval = 0;
            if (sum < lval + rval) {
                sum = lval + rval;
            }
        }
        dp[cur_id][i][2] = sum + room_point[cur_id];
    }
}
/*
TreeNode_p TreeGenerate(int root_id, vector<vector<int>> room_map,
                        vector<int> room_point) {
    int room_number = room_point.size();
    queue<int> id_queue;
    queue<TreeNode_p> node_queue;
    TreeNode_p head = new struct treeNode(root_id, room_point[root_id]);

    // we choose a node with degree 1 as the root of the tree;
    id_queue.push(root_id);
    id_queue.push(-1);
    node_queue.push(head);
    while (!node_queue.empty()) {
        int cur_id;
        TreeNode_p cur_node;
        TreeNode_p tmp;
        int cnt;

        cur_node = node_queue.front();
        node_queue.pop();

        // handle the left child tree
        cur_id = id_queue.front();
        id_queue.pop();
        if (cur_id != -1) {
            tmp = new struct treeNode(cur_id, room_point[root_id]);
            cur_node->left = tmp;

            cnt = 0;
            for (int i = 0; i < room_number; i++) {
                if (room_map[cur_id][i] == 1) {
                    room_map[cur_id][i] = room_map[i][cur_id] = 0;
                    id_queue.push(i);
                    cnt++;
                }
            }
            // if the any child exists
            if (cnt > 0) {
                node_queue.push(cur_node->left);
                if (cnt == 1) id_queue.push(-1);
            }
        }
        // handle the right child tree
        cur_id = id_queue.front();
        id_queue.pop();
        if (cur_id != -1) {
            tmp = new struct treeNode(cur_id, room_point[root_id]);
            cur_node->right = tmp;

            cnt = 0;
            for (int i = 0; i < room_number; i++) {
                if (room_map[cur_id][i] == 1) {
                    room_map[cur_id][i] = room_map[i][cur_id] = 0;
                    id_queue.push(i);
                    cnt++;
                }
            }
            // if the any child exists
            if (cnt > 0) {
                node_queue.push(cur_node->right);
                if (cnt == 1) id_queue.push(-1);
            }
        }
    }  // while ends
    auto p = head;
    head = head->left;
    delete p;
    return head;
}

dprogram(TreeNode_p p, m) {
    if (m == 0) return 0;
}
*/

int main(int argc, char **argv) {
    cin >> n >> m;

    vector<int> room_point(n);
    vector<vector<int>> room_map(n);

    for (auto &i : room_map) {
        i = vector<int>(n, 0);
    }

    for (int i = 0; i < n; i++) {
        cin >> room_point[i];
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        room_map[x][y] = room_map[y][x] = 1;
    }

    // there must be a node with degree 1, we choose it to generate the binary
    // tree
    int root_id;
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += room_map[i][j];
        }
        if (degree == 1) {
            root_id = i;
            break;
        }
    }

    TreeNode_p head = TreeGenerate(root_id, room_map, room_point);

    for (int i = 1; i <= m; i++) {
        dprogram(head, i);
    }

    return 0;
}
