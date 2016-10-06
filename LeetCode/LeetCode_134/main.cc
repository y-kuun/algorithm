#include <vector>
using namespace std;

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int res = 0;
        int sum = 0;
        int total;
        for (int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                res = i;
            }
        }
        return total >= 0 ? res + 1 : -1;
    }
};

/*
class Solution {
   public:
    bool startfrom(vector<int>& gas, vector<int>& cost, int i) {
        int cg = gas[i];
        int n = gas.size();
        for (int j = (i + 1) % n;; j = (j + 1) % n) {
            if (j != 0)
                cg = cg - cost[j - 1];
            else
                cg = cg - cost[n - 1];

            if (cg < 0) {
                return false;
            }
            if (j == i) {
                break;
            }
            cg = cg + gas[j];
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            if (startfrom(gas, cost, i)) {
                return i;
            }
        }
        return -1;
    }
};
*/