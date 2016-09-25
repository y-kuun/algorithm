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

int main() {
    std::thread t(fib, 10);
    std::future<int> f1 = std::async(fib, 10);

    std::cout << f1.get() << std::endl;
    return 0;
}