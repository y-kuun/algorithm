class Solution {
  public:
    void recursion(vector<vector<int>> &res, vector<int> &gp,
                   const vector<int> &can, int target) {
        if (target == 0) {
            vector<int> tmp(gp);
            sort(tmp.begin(), tmp.end());
            if (find(res.begin(), res.end(), tmp) == res.end())
                res.push_back(tmp);
        }
        if (target < 0)
            return;
        for (auto i : can) {
            gp.push_back(i);
            recursion(res, gp, can, target - i);
            gp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> gp;
        vector<vector<int>> res;
        recursion(res, gp, candidates, target);
        return res;
    }
};