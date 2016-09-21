#include <iostream>
#include <vector>
using namespace std;

int main() {
    int target;
    int size;
    cin >> target;
    cin >> size;
    vector<int> nums;
    nums.clear();
    int tmp;
    while (size--) {
        cin >> tmp;
        nums.push_back(tmp);
    }

    int low = 0;
    int high = nums.size() - 1;
    int mid;
    bool flag = false;
    while (low <= high) {
        mid = (high - low) / 2 + low;
        if (nums[mid] == target) {
            flag = true;
            break;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        }
    }
    if (flag)
        cout << mid << endl;
    else {
        cout << -1 - low << endl;
    }
}
