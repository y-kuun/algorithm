#include <cstdio>
#include <future>
#include <iostream>

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
    int ykdb = 0;
    const int ykda = 0;
    std::cout << (void *)&ykda << std::endl;
    std::cout << (void *)&ykdb << std::endl;

    return 0;
}