#include <vector>
using namespace std;

// 实际上需要找的是比现在这个序列刚好大一个的序列
// 先

class Solution {
   public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) return;
        int k = nums.size() - 1;
        int i = nums.size() - 2;
        stack<int> st;
        st.push(k);
        while (i >= 0 && nums[st.top()] <= nums[i]) {
            st.push(i);
            i--;
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        } else {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                k = st.top();
                st.pop();
            }
            swap(nums, k, i);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
    }
};