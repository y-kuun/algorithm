#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

using namespace std;

std::mutex g_mutex;

void print_1_to_10(string name) {
    for (int i = 0; i < 10; i++) {
        g_mutex.lock();
        cout << name << " : " << i + 1 << endl;
        g_mutex.unlock();
    }
}

int main() {
    std::thread t1(print_1_to_10, "T1");
    std::thread t2(print_1_to_10, "T2");
    cout << "Start!" << endl;
    t1.join();
    t2.join();
    cout << "Finish!" << endl;
}