#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//

class Solution {
   public:
    int min(int a, int b) { return a > b ? b : a; }
    int rainSum(vector<int>& height, int i, int j) {
        int hgt = min(height[j], height[i]);
        int sum = 0;
        for (int n = i + 1; n < j; n++) {
            sum += hgt - height[n];
            height[n] = hgt;
        }
        return sum;
    }
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            if (st.empty() && height[i] != 0) {
                st.push(i);
            } else if (!st.empty()) {
                if (height[st.top()] > height[i]) {
                    st.push(i);
                } else {
                    while (st.size() > 1 && height[st.top()] < height[i]) {
                        st.pop();
                    }
                    int loc = st.top();
                    if (height[st.top()] <= height[i]) st.pop();
                    st.push(i);
                    res += rainSum(height, loc, i);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    s.trap(vec);
}