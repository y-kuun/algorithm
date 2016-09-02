#include <iostream>
#include <stack>
using namespace std;

//  循环条件需要仔细思考

class Solution {
   public:
    bool isValidSerialization(string preorder) {
        if (preorder[0] == '#' && preorder.size() == 1)
            return true;
        else if (preorder[0] == '#' && preorder.size() > 1)
            return false;
        stack<int> st;
        stack<char> cst;
        preorder = preorder + ',';
        cout << preorder << endl;
        st.push(0);
        int i = 1;
        while (preorder[i++] != ',') {
        }
        int tick = 0;
        while (i < preorder.size() && st.size() > 0) {
            while (i < preorder.size() && preorder[i] != '#') {
                if (preorder[i] == ',') st.push(i);
                i++;
            }
            if (i < preorder.size()) cst.push('#');
            if (st.size() > 0 && cst.size() > 1) {
                cst.pop();
                st.pop();
            }
            i = i + 2;
        }
        if (cst.size() == 1 && st.empty() && i >= preorder.size()) {
            return true;
        } else
            return false;
    }
};

int main() {
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    return 0;
}