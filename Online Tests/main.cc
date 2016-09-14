// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <cstring>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    set<int> st(vec.begin(), vec.end());

    auto it = st.begin();
    for (; it != st.end();) {
        if (*it == 5) {
            st.erase(it++);
        } else {
            cout << *it << " ";
            it++;
        }
    }
    cout << endl;
    auto vit = vec.begin();
    for (; vit != vec.end();) {
        if (*vit == 7) {
            vec.erase(vit);
        } else {
            cout << *vit << " ";
            vit++;
        }
    }
    cout << endl;
}