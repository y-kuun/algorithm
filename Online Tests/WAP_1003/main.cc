// Exam2 Wireless ROuters
// Author:  Yukun Du
// Date:    2010-10-03
// Description: all the N room with N-1 door can be regarded as a binary tree

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct treeNode {
    int id;
    int point;
    struct treeNode *left;
    struct treeNode *right;
    treeNode(int _id = 0, int _point = 0)
        : id(_id), point(_point), left(NULL), right(NULL){};
};

using TreeNode_p = struct treeNode *;

int dp[3][1001][101] = {0};  // for the tree dp

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

int main(int argc, char **argv) {
    int n, m;
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
