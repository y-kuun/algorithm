#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int len = heights.size();
        int res = 0;
        if (len == 0) {
            return res;
        }
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (st.empty() || heights[i] > heights[st.top()]) {
                st.push(i);
            } else {
                int lloc = st.top();
                st.pop();
                int tmp;
                if (st.empty()) {
                    tmp = i;
                } else
                    tmp = i - st.top() - 1;
                res = max(res, heights[lloc] * tmp);
                i--;
            }
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> v = {2, 1, 2};
    cout << s.largestRectangleArea(v) << endl;
    return 0;
}