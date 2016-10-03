// Exam1 Magic Cube
// Author:  Yukun Du
// Date:    2010-10-03
// Description: overlayed small cubes is not considered, and only one solution
// is guaranteed
// ID:  f3c2f5e2-a2ff-4103-b30d-9ca82d52375d
// ID:  fa23d473-c923-4e8f-8956-c428ecb131dc

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct cube {
   public:
    int ***m_cube;
    int size;
    cube(void) : m_cube(NULL), size(0){};
    explicit cube(int _size) : size(_size) {
        m_cube = new int **[size];
        for (int i = 0; i < size; i++) {
            m_cube[i] = new int *[size];
            for (int j = 0; j < size; j++) {
                m_cube[i][j] = new int[size];
            }
        }
    };
    ~cube() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                delete[] m_cube[i][j];
            }
        }
        for (int i = 0; i < size; i++) {
            delete[] m_cube[i];
        }
        delete[] m_cube;
    };
    // default copy function is not allowed
    cube(struct cube &) = delete;
    struct cube &operator=(struct cube &) = delete;
};  // struct cube

using cube_p = struct cube *;

// init_cube, read a size * size *size cube from stdin
void init_cube(int size, int ***cube) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                cin >> cube[i][j][k];
            }
        }
    }
}  // init_cube ends

// if a small cube can be put in the (x,y,z) location of the big cube return
// true, otherwise return false;
// if return true, the relevant area of big_cube is setted to -1 as visited
bool isMatch(cube_p small_cube, cube_p big_cube, int x, int y, int z, int p) {
    if (x + small_cube->size > big_cube->size) return false;
    if (y + small_cube->size > big_cube->size) return false;
    if (z + small_cube->size > big_cube->size) return false;
    for (int i = 0; i < small_cube->size; i++) {
        for (int j = 0; j < small_cube->size; j++) {
            for (int k = 0; k < small_cube->size; k++) {
                if ((small_cube->m_cube[i][j][k] +
                     big_cube->m_cube[x + i][y + j][z + k]) %
                        p !=
                    0) {
                    return false;
                }
            }
        }
    }
    //  mark as visited
    for (int i = 0; i < small_cube->size; i++) {
        for (int j = 0; j < small_cube->size; j++) {
            for (int k = 0; k < small_cube->size; k++) {
                big_cube->m_cube[x + i][y + j][z + k] = -1;
            }
        }
    }

    return true;
}  // isMatch ends

int main(int argc, char **argv) {
    // read from a input file
    // freopen("input.txt", "r+", stdin);

    int n, m, p;
    cin >> m >> n >> p;

    cube_p big_cube = new struct cube(m);
    vector<cube_p> scube_vec;

    init_cube(m, big_cube->m_cube);

    // read each small cube from stdin
    for (int i = 0; i < n; i++) {
        int tmp;
        cube_p tmp_scp;
        cin >> tmp;
        tmp_scp = new struct cube(tmp);
        init_cube(tmp, tmp_scp->m_cube);
        scube_vec.push_back(tmp_scp);
    }

    // search all the bigcube to put
    for (int i = 0; i < scube_vec.size(); i++) {
        bool flag = false;
        for (int x = 0; x < m && !flag; x++) {
            for (int y = 0; y < m && !flag; y++) {
                for (int z = 0; z < m && !flag; z++) {
                    if (big_cube->m_cube[x][y][z] != -1 &&
                        isMatch(scube_vec[i], big_cube, x, y, z, p)) {
                        cout << x << " " << y << " " << z << endl;
                        // find a place to put, now search location for the next
                        // cube
                        flag = true;
                    }
                }
            }
        }
    }

    // delete the dynamic allocated memory
    delete big_cube;
    for (auto &i : scube_vec) {
        delete i;
    }

    return 0;
}  // main ends