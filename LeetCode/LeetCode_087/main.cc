#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
    public:
        bool isScramble(string s1, string s2) {
            return iss(s1.begin(), s1.end(), s2.begin(), s2.end());
        };
        template<typename InputIterator>
            bool iss(InputIterator lft1, InputIterator rht1, InputIterator lft2, InputIterator rht2);
        template<typename InputIterator>
            bool isCompared(InputIterator lft1, InputIterator rht1, InputIterator lft2, InputIterator rht2);
};


template<typename InputIterator>
bool Solution::isCompared(InputIterator lft1, InputIterator rht1, InputIterator lft2, InputIterator rht2){
    string str1(lft1, rht1);
    string str2(lft2, rht2);
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    auto l1 = str1.begin();
    auto r1 = str1.end();
    auto l2 = str2.begin();
    auto r2 = str2.end();
    while(l1 != r1 && l2 != r2){
        if(*l1 != *l2)
            return false;
        l1++;
        l2++;
    }
    return true;
}


// 输入的两个迭代器的距离一定是一样的
template<typename InputIterator>
bool Solution::iss(InputIterator lft1, InputIterator rht1, InputIterator lft2, InputIterator rht2){
    if(distance(lft1, rht1) == 0 && distance(lft2, rht2) == 0)
        return false;
    if(distance(lft1, rht1) == 1 && distance(lft2, rht2) == 1)
        return *lft1 == *lft2;
    if(distance(lft1, rht1) == 2 && distance(lft2, rht2) == 2)
        return (*lft1 == *lft2 && *(lft1+1) == *(lft2+1)) || ( *lft1 == *(lft2+1) && *(lft1+1) == *lft2);
    // while only one element
    bool ans = false;
    auto search_range = lft1;
    while(search_range != rht1 && !ans){
        auto it1 = find(search_range, rht1, *lft2);
        search_range = next(it1);
        if(it1 == rht1)
            break;
        auto resotred_it1 = it1;
        // 需要判断是否进行迭代！
        while(it1 >= lft1 + 1){
            int length = distance(lft1, it1);
            auto it2 = next(lft2, length);
            it2 = next(lft2, distance(lft1, rht1 - length));
            // 将得到的元素，划分到右半子树，要求右子树不能含有全部元素
            // if( distance(it1, rht1) < distance(lft1, rht1))
            if( isCompared(lft1, it1, it2, rht2)){
                ans = ans || ( iss(lft1, it1, it2, rht2) && iss(it1, rht1, lft2, it2) );
            }
            it1--;
        }
        it1 = resotred_it1;
        while(it1 < rht1 - 1){
            int length = distance(lft1, it1);
            auto it2 = next(lft2, length);
            // 必须一分为二
            // 将找到的元素，划分到左半子树，要求左子树不能含有全部元素
            // if( distance(lft1,next(it1)) < distance(lft1, rht1))
            if( isCompared(lft1, next(it1), lft2, next(it2))){
                ans = ans || ( iss(lft1, next(it1), lft2, next(it2)) && iss(next(it1), rht1, next(it2), rht2));
            }
            it1++;

        }
    }
    return ans;
}


int main(){
    Solution s;
    string str1("ccabcbabcbabbbbcbb");
    string str2("bbbbabccccbbbabcba");
    cout<<s.isScramble(str1, str2);
    return 0;
}
