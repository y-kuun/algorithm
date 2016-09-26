#include <future>
#include <iostream>
#include <queue>

std::mutex g_lock;
std::condition_variable cv;
std::queue<int> que;
std::vector<int> vec(10, 0);

bool ready = false;

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

void func(int i) {
    std::unique_lock<std::mutex> lck(g_lock);

    while (vec[i] == 0)
        cv.wait(lck);  // 先释放lock，并且阻塞，等待notify，接受到notify
                       // 将会从阻塞恢复并且重新锁住

    std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
    std::cout << i << " Hello!" << std::endl;
    std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
}

void allgo(void) { cv.notify_all(); }

int main() {
    std::thread t_arr[10];

    for (int i = 0; i < 10; i++) {
        t_arr[i] = std::thread(func, i);
    }

    std::cout << "10 threads ready to race .. " << std::endl;

    allgo();

    for (auto& th : t_arr) th.join();

    return 0;
}