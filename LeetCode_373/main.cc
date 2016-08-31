class Solution {
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1,
                                          vector<int> &nums2, int k) {

        vector<pair<int, int>> res;
        int arr[nums1.size() + 1];

        if (k == 0 || nums1.size() == 0 || nums2.size() == 0)
            return res;

        for (int i = 0; i < nums1.size() + 1; i++) {
            arr[i] = 0;
        }

        int tmp = nums1.size() * nums2.size();
        k = tmp > k ? k : tmp;

        int xx, min_sum;
        while (k > 0) {
            min_sum = INT_MAX;
            for (int i = 0; i < nums1.size(); i++) {
                if (arr[i] < nums2.size() &&
                    min_sum >= nums1[i] + nums2[arr[i]]) {
                    xx = i;
                    min_sum = nums1[xx] + nums2[arr[xx]];
                }
            }

            res.push_back(pair<int, int>(nums1[xx], nums2[arr[xx]++]));
            k--;
        }

        return res;
    }
};