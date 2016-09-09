// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        bool flag;
        if(left == right && isBadVersion(n))
            return 1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(isBadVersion(mid)){
                right = mid - 1;
                flag = true;
            }else {
                left = mid + 1;
                flag = false;
            }
        }
        if(flag)
            return right + 1;
        else return left;
    }
};
