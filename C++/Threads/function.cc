#include <exception>
#include <functional>
#include <iostream>

using THIS_FUNC = std::function<int(int)>;

int test(int a) {
    std::cout << "Test" << std::endl;
    return a;
}

auto lamda = [](int a, int b) -> int {
    std::cout << "LAMDA" << std::endl;
    return a + b;
};

int main() {
    THIS_FUNC func0 = test;
    std::cout << func0(10) << std::endl;

    throw std::runtime_error("NOTHING!");

    THIS_FUNC func1 = std::bind(lamda, std::placeholders::_1, 10);
    std::cout << func1(10) << std::endl;

    return 0;
}