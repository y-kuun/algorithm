#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> &split(vector<int> &res, int n) {
        res.clear();
        while (n) {
            int tmp = n % 10;
            n = n / 10;
            res.push_back(tmp);
        }
        return res;
    }
    int sqsum(const vector<int> &ns) {
        int sum = 0;
        for (auto i : ns) {
            sum += i * i;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        unordered_set<int> us;
        vector<int> ns;
        split(ns, n);
        int tmp;
        while ((tmp = sqsum(ns)) != 1) {
            cout << tmp << endl;
            if (us.find(tmp) == us.end())
                us.insert(tmp);
            else
                return false;
            split(ns, tmp);
        }
        return true;
    }
};