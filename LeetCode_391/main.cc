#include <climits>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Point {
  public:
    Point(int x, int y) : _x(x), _y(y) {}
    bool firend operator==(const Point rhs) {
        return (_x == rhs._x) && (_y == rhs._y);
    }
    bool firend operator<(const Point rhs) {
        return (_x < rhs._x) && (_y < rhs._y);
    }

  private:
    int _x;
    int _y;
}

class Solution {
  public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        // (x, y) will be presented in string as 'xy\0'
        unordered_set<string> uset_string;
        unordered_set<Point> uset_point;

        int gx_bl(INT_MAX);
        int gy_bl(INT_MAX);
        int gx_tr(-1);
        int gy_tr(-1);

        vector<string> vec_string(4);
        string stra, strb, strc, strd;

        int sum_area(0);

        // get the max bottom left point and the max top right
        for (auto rect : rectangles) {
            if (gx_bl > rect[0]) {
                gx_bl = rect[0];
            }
            if (gy_bl > rect[1]) {
                gy_bl = rect[1];
            }
            if (gx_tr < rect[2]) {
                gx_tr = rect[2];
            }
            if (gy_tr < rect[3]) {
                gy_tr = rect[3];
            }
            sum_area += (rect[2] - rect[0]) * (rect[3] - rect[1]);

            vec_string[0] = std::to_string(rect[0]) + std::to_string(rect[1]);
            vec_string[1] = std::to_string(rect[0]) + std::to_string(rect[3]);
            vec_string[2] = std::to_string(rect[2]) + std::to_string(rect[1]);
            vec_string[3] = std::to_string(rect[2]) + std::to_string(rect[3]);

            for (auto str : vec_string) {
                if (uset_string.find(str) == uset_string.end()) {
                    uset_string.insert(str);
                } else {
                    uset_string.erase(str);
                }
            }
        }

        if (sum_area != (gx_tr - gx_bl) * (gy_tr - gy_bl)) {
            cout << "area problem " << sum_area << endl;
            cout << gx_tr << " " << gy_tr << " " << gx_bl << " " << gy_bl
                 << endl;
            return false;
        }

        vec_string[0] = std::to_string(gx_bl) + std::to_string(gy_bl);
        vec_string[1] = std::to_string(gx_tr) + std::to_string(gy_bl);
        vec_string[2] = std::to_string(gx_bl) + std::to_string(gy_tr);
        vec_string[3] = std::to_string(gx_tr) + std::to_string(gy_tr);

        // perfect rectangle can only has 4 points from the rectangle which is
        // excluded
        // all other points will be shared twice or for four times
        if (uset_string.size() != 4) {
            cout << "size problem!" << endl;
            return false;
        }

        for (auto str : vec_string) {
            cout << str << endl;
            if (uset_string.find(str) == uset_string.end())
                return false;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    return 0;
}