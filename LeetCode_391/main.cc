#include <unordered_set> 
#include <vector> 
#include <iostream> 
using namespace std; 

namespace std {
    template <> struct hash < Solution::Point >  {
        size_t operator()(const Point & pt)const {
            return std::hash < int > ()(pt.x)^ std::hash < int > ()(pt.y); 
        }
    }; 
}

class Solution {
public:
    struct Point {
        private:
            int _x; 
            int _y; 
        public:
                Point(int x, int y):_x(x), _y(y) {}; 
                bool operator == (const Point & y) {
                    return (this-> _x - y._x) && (this-> _y - y._x); 
                }
    }; 
    bool isRectangleCover(vector < vector < int >  >& rectangles) {
        unordered_set < Solution::Point > map; 

        int g_x_bl = (1 << 32) - 1; 
        int g_y_bl = (1 << 32) - 1; 
        int g_x_tr = -1; 
        int g_y_tr = -1; 
        int sum_area = 0; 
        
        for (auto it = rectangles.begin(); it != rectangles.end(); it++) {
            int x_bl = ( * it)[0]; 
            int y_bl = ( * it)[1]; 
            int x_tr = ( * it)[2]; 
            int y_tr = ( * it)[3]; 
            if (g_x_bl > x_bl) {
                g_x_bl = x_bl; 
            }
            if (g_y_bl > y_bl) {
                g_y_bl = y_bl; 
            }
            if (g_x_tr < x_tr) {
                g_x_tr = x_tr; 
            }
               
            if (g_y_tr < y_tr) {
                g_y_tr = y_tr; 
            }
            sum_area +  = (x_tr - x_bl) * (y_tr - y_bl); 
        }

        if (sum_area != (g_x_tr - g_x_bl) * (g_y_tr - g_y_bl)) {
            return false; 
        }

        for (auto it = rectangles.begin(); it != rectangles.end(); it++) {
            
        }
        return true; 
    }
    private:
       
}; 