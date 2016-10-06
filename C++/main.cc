#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>

using namespace std;

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
    base(int i = 1) : bi(i) { cout << "BASE!" << endl; };
    base(base& rhs) {
        bi = rhs.bi;
        cout << "COPY" << endl;
    }
    base& operator=(const base& rhs) {
        bi = rhs.bi;
        cout << "copy=" << endl;
        return *this;
    }
    virtual void vfunc01(void) { std::cout << "base::vfunc01" << endl; }
    virtual void vfunc02(int) { std::cout << "base::vfunc02" << endl; }
    virtual void vfunc03(base*) { std::cout << "base::vfunc03" << endl; }
    void print(void) { std::cout << bi << std::endl; }
    void set(int i = 0) { bi = i; }
    void add(base& a) { cout << a.bi + bi << endl; }

   private:
    int bi;
};

class drived : public base {
   private:
    int di;

   public:
    // using base::vfunc03;
    drived(int i = 0) : di(i), base(i) { cout << "DRIVED" << endl; };
    void vfunc01(void) { std::cout << "drived::vfunc01" << endl; }
    void vfunc03(base*) { std::cout << "drived::vfunc03" << endl; }
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

void sum(int a, int b) { cout << a + b << endl; }

int main() {
    base* bp;
    bp = new drived;
    base b;
    drived d;

    bp->vfunc01();
    bp->vfunc03(&d);
    d.vfunc03(&d);
    d.vfunc03(&b);

    /*

    int i = 10;
    const int* pi = &i;

    int c[10] = {0};
    int* pd = new int[10];

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::set<int> sarr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::stack<int, list<int> > st;

    auto func = [&arr]() -> void {
        arr[arr.size() - 1] = 10;
        cout << "Lamda Func" << endl;
        for (auto i : arr) cout << i << " ";
        cout << endl;
    };

    func();

    for (auto it = arr.begin(); it != arr.end();) {
        std::cout << *it << " ";
        if (*it == 5) {
            arr.erase(it);
        } else
            it++;
        std::cout << *it << std::endl;
    }

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