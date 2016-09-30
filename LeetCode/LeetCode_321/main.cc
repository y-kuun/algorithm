#include <iostream>
#include <vector>

using namespace std;

//思路: 也是麻烦的一题. 思路是从nums1中取i个最大值,从nums2中取k-i个最大值,
//然后枚举各个i,然后合并取比较大的. 但是在具体的实现中其实还是比较麻烦的.
//首先从一个数组取i个大的值时, 我们要尽量保留其降序的序列,
//除非剩余的元素个数不足我们要取的个数
//然后是合并的时候, 如果两个元素的当前元素相等,
//那么我们还要考虑其后序元素的大小.
//

void print_arr(const vector<int> num) {
    for (auto i : num) {
        cout << i << " ";
    }
    cout << endl;
}

// only will comapare vector with the same length
bool compare(vector<int> a, vector<int> b) {
    int lena = a.size();
    int lenb = b.size();
    int i = 0;
    int j = 0;
    while (i < lena && j < lenb) {
        if (a[i] > b[i]) {
            return true;
        } else if (a[i] < b[i]) {
            return false;
        }
        i++;
        j++;
    }
    return false;
}

// find elemets in nums which construct a larger
vector<int> getMax(vector<int> nums, int k) {
    vector<int> vec;
    int drop = nums.size() - k;
    for (int i = 0; i < nums.size(); i++) {
        while (drop > 0 && vec.size() && nums[i] > vec.back()) {
            drop--;
            vec.pop_back();
        }
        vec.push_back(nums[i]);
    }
    vec.resize(k);
    return vec;
}

vector<int> merge(vector<int> nums1, vector<int> nums2) {
    vector<int> res;
    while (nums1.size() + nums2.size() > 0) {
        vector<int>& tmp = nums1 > nums2 ? nums1 : nums2;
        res.push_back(tmp[0]);
        tmp.erase(tmp.begin());
    }
    return res;
}

class Solution {
   public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        for (int i = max(k - len2, 0); i <= min(k, len1); i++) {
            vector<int> tmp1 = getMax(nums1, i);
            vector<int> tmp2 = getMax(nums2, k - i);
            vector<int> tmp = merge(tmp1, tmp2);
            if (tmp > res) {
                res = tmp;
            }
        }
        return res;
    }
};

int main(void) {
    vector<int> a{3, 4, 6, 5};
    vector<int> b{9, 1, 2, 5, 8, 3};
    Solution s;
    s.maxNumber(a, b, 5);
    return 0;
}