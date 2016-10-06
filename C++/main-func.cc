#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class test {
   public:
    void func1() const;
    static void gfunc2();

   private:
    void func3();
};

// static 关键字只需要出现在声明当中
// 而const 关键字可以出现在定义当中

void test::func1() const { cout << "normal func1!" << endl; }
void test::gfunc2() { cout << "normal func2!" << endl; }
void test::func3() { cout << "normal func3!" << endl; }

int main(int argc, char** argv) {
    test t;
    test::gfunc2();
    return 0;
}