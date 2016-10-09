#include <cstdlib>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool isOperator(string str) {
        return str.size() == 1 && string("+-*/").find(str) != string::npos;
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opd;
        int opd1;
        int res;
        for (auto i : tokens) {
            if (isOperator(i)) {
                if (opd.size() < 2) return 0;
                opd1 = opd.top();
                opd.pop();
                res = opd.top();
                opd.pop();
                switch (i[0]) {
                    case '+':
                        res += opd1;
                        break;
                    case '-':
                        res -= opd1;
                        break;
                    case '*':
                        res *= opd1;
                        break;
                    case '/':
                        res /= opd1;
                        break;
                }
                opd.push(res);
            } else {
                opd.push(stoi(i));
            }
        }
        if (opd.empty()) {
            return 0;
        } else {
            return opd.top();
        }
    }
};