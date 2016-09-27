#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <future>
#include <iostream>
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

int main() {
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
    return 0;
}