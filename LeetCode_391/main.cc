#include <iostream>
#include <unordered_set>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int> >& rectangles)
    {
        int gx_bl(INT_MAX);
        int gy_bl(INT_MAX);
        int gx_tr(-1);
        int gy_tr(-1);

        int sum_area(0);

        // get the max bottom left point and the max top right
        for(auto rect : rectangles)
        {
            if(gx_bl > rect[0])
            {
                gx_bl = rect[0];
            }
            if(gy_bl > rect[1])
            {
                gy_bl = rect[1];
            }
            if(gx_tr < rect[2])
            {
                gx_tr = rect[2];
            }
            if(gy_tr > rect[3])
            {
                gy_tr = rect[3];
            }
        }
    }
};

int main(int argc, char* argv[])
{
    cout<<"Hello World!"<<endl;
    return 0;
}