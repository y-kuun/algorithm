#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <iostream>
#include <set>
#include <vector>

int fib(int x = 1) {
    if (x == 1) return 1;
    if (x == 2) return 1;
    int a = 1;
    int b = 1;
    int sum;
    for (int i = 3; i <= x; i++) {
        sum = a + b;
        a = b;
        b = sum;
        std::cout << sum << std::endl;
    }
    return sum;
}

class base {
   public:
    base(int i = 1) : bi(i){};
    void print(void) { std::cout << bi << std::endl; }
    void set(int i = 0) { bi = i; }

   private:
    int bi;
};

class drived : public base {
   private:
    int di;

   public:
    drived(int i) : di(i), base(i){};
};

void func() {
    char str[10];
    gets(str);
    std::cout << str << std::endl;
}

int a[100];
static int b[100];

void print_arr(int* p, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int i = 10;
    const int* pi = &i;

    int c[10] = {0};
    int* pd = new int[10];

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::set<int> sarr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it = sarr.begin(); it != sarr.end();) {
        auto p = it;
        it++;
        std::cout << *p << " ";
        if (*p == 5) {
            sarr.erase(p);
        }
        std::cout << *p << std::endl;
    }

    for (auto i : c) {
        std::cout << i << std::endl;
    }

    std::cout << (void*)&c << " " << (void*)&c[0] << std::endl;
    /*
    print_arr(b, 100);
    print_arr(c, 100);
    print_arr(pd, 100);

    std::cout << *pi << std::endl;
    i = 11;
    std::cout << *pi << std::endl;

        int n, m;
        std::cin >> n >> m;
        srand(time(NULL));
        std::vector<int> vec;
        vec.push_back(0);
        vec.push_back(n);

        for (int i = 0; i < m - 1; i++) {
            vec.push_back(rand() % n);
        }
        std::sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); i++) {
            std::cout << vec[i] - vec[i - 1] << " ";
        }
        std::cout << std::endl;
        */
    return 0;
}