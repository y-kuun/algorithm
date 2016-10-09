#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace ykal {

template <typename InputIt>
InputIt partition(InputIt begin, InputIt end) {
    InputIt ploc = begin;
    auto key = *(end - 1);
    auto it = ploc;
    while (it < end - 1) {
        if (*it < key) {
            iter_swap(it, ploc);
            ploc++;
        }
        it++;
    }
    iter_swap(ploc, end - 1);
    return ploc;
}

template <typename InputIt>
void qsort(InputIt begin, InputIt end) {
    if (begin + 1 == end || begin >= end) {
        return;
    } else {
        InputIt ploc = partition(begin, end);
        for (InputIt it = begin; it != end; it++) {
            cout << *it << " ";
        }
        cout << endl;
        qsort(begin, ploc);
        qsort(ploc + 1, end);
    }
}
}

int main(int argc, char** argv) {
    vector<string> vec = {"123123",   "absdsd", "gffg",
                          "435sdasd", "oiuwer", "zxcsdfr"};

    vector<int> arr = {1, 5, 6, 7, 3, 3, 4, 5, 6, 7, 8, 9};

    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
    auto it = next(arr.begin(), distance(arr.begin(), arr.end()) / 2);
    cout << *it << endl;
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    auto vvec(vec);
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
    ykal::qsort(vec.begin(), vec.end());
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
    cout << "***************" << endl;

    for (auto i : vvec) {
        cout << i << " ";
    }
    cout << endl;
    sort(vvec.begin(), vvec.end());
    for (auto i : vvec) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}