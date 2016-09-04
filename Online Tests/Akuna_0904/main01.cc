/*
 * Complete the function below.
 */
#include <unordered_set>
using namespace std;

bool recrusion(unordered_multiset<int> &uns, int max, int cur_val) {
    for (auto it = uns.begin(); it != uns.end(); it++) {
        int tmp = *it;
        uns.erase(*it);
        if (cur_val + tmp <= max && uns.find(cur_val + tmp) != uns.end()) {
            uns.erase(cur_val + tmp);
            return true;
        } else if (cur_val + tmp <= max && recrusion(uns, max, cur_val + tmp)) {
            return true;
        } else
            uns.insert(tmp);
    }
    return false;
}

int subset_sum_remove(vector<int> nums) {
    unordered_multiset<int> uns(nums.begin(), nums.end());
    int max = -1;
    for (auto val : nums) {
        if (max < val) {
            max = val;
        }
    }
    while (recrusion(uns, max, 0)) {
        cout << uns.size() << endl;
    }
    return uns.size();
}
