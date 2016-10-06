#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

std::vector<int*> vec;

template <typename T, size_t N>
void func(int*& p) {
    T b[N];
    for (auto& i : b) {
        i = 1234;
    }
    cout << (void*)p << endl;
    cout << (void*)b << endl;

    T* bp = b;

    p = std::move(b);

    cout << (void*)p << endl;
    cout << (void*)b << endl;

    p = std::move(bp);

    cout << (void*)p << endl;
    cout << (void*)bp << endl;

    std::for_each(std::begin(b), std::end(b),
                  [](T val) { cout << val << endl; });
}

int main(int argc, char** argv) {
    std::unique_ptr<int> p1(new int(3));
    std::unique_ptr<int> p2;

    std::shared_ptr<int> sp1(new int(4));
    std::shared_ptr<int> sp2;

    std::unique_ptr<int[]> p;

    int arr[10] = {1, 2, 3, 4, 5};
    int* pp = arr;

    pp = std::move(arr);

    func<int, 3>(pp);

    cout << "!!!!" << endl;

    for (int i = 0; i < 5; i++) {
        cout << pp[i] << endl;
    }

    for (int i = 0; i < 5; i++) {
        cout << pp[i] << endl;
    }

    /*
        int* p = arr;

        std::make_heap(std::begin(arr), std::begin(arr) + 5);

        arr[5] = 100;

        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;

        std::push_heap(std::begin(arr), std::begin(arr) + 6);

        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;

        std::pop_heap(std::begin(arr), std::begin(arr) + 6);

        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;

        std::cout << p1.get() << std::endl;
        std::cout << (p1.get() == nullptr) << std::endl;
        std::cout << p2.get() << std::endl;
        std::cout << (p2.get() == nullptr) << std::endl;

        p2 = std::move(p1);

        std::cout << p1.get() << std::endl;
        std::cout << (p1.get() == nullptr) << std::endl;
        std::cout << p2.get() << std::endl;
        std::cout << (p2.get() == nullptr) << std::endl;
    std::cout << sp1.get() << std::endl;
    std::cout << (sp1.get() == nullptr) << std::endl;
    std::cout << sp2.get() << std::endl;
    std::cout << (sp2.get() == nullptr) << std::endl;

    // sp2 = std::move(sp1);

    sp2 = sp1;

    std::cout << sp1.get() << std::endl;
    std::cout << (sp1.get() == nullptr) << std::endl;
    std::cout << sp2.get() << std::endl;
    std::cout << (sp2.get() == nullptr) << std::endl;

        */
    return 0;
}