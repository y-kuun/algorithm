#ifndef _WORKER_POOL_H_
#define _WORKER_POOL_H_

// https://my.oschina.net/keyven/blog/643587

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

template <typename T>
class WorkerPool {
   public:
    typedef WorkerPool<T> THIS_TYPE;
    typedef std::function<void(T*)> WorkerProc;
    typedef std::vector<std::thread*> ThreadVec;  // 线程池任务队列
    WorkerPool() { active_ = false; }
    virtual ~WorkerPool() {
        for (ThreadVec::iterator it = all_thread_.begin();
             it != all_thread_.end(); ++it)
            delete *it;
        all_thread_.clear();
    }
    void Start(WorkerProc f, int worker_num = 1) {
        active_ = true;
        all_thread_.resize(worker_num);
        for (int i = 0; i < worker_num; i++) {
            all_thread_[i] =
                new std::thread(std::bind(&THIS_TYPE::consumer, this));
        }
        proc_ = f;
    }
    //生产者
    void Push(T* t) {
        std::unique_lock<std::mutex> lck(
            mutex_);  // lock构造时自动上锁，析构时自动解锁
        task_.push(t);
        cv_.notify_one();  // 若唤醒队列中有阻塞线程，则唤醒它
    }
    void Stop() {
        //等待所有的任务执行完毕
        mutex_.lock();
        while (!task_.empty()) {
            mutex_.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            cv_.notify_one();
            mutex_.lock();
        }
        mutex_.unlock();
        //关闭连接后，等待线程自动退出
        active_ = false;
        cv_.notify_all();
        for (ThreadVec::iterator it = all_thread_.begin();
             it != all_thread_.end(); ++it)
            (*it)->join();
    }

   private:
    //消费者
    void consumer() {
        //第一次上锁
        std::unique_lock<std::mutex> lck(mutex_);  // lock构造时自动上锁
        while (active_) {
            //如果是活动的，并且任务为空则一直等待
            while (active_ && task_.empty())
                cv_.wait(lck);  // 阻塞本线程，暂时解锁，并加入到唤醒队列中
            //如果已经停止则退出
            if (!active_) break;
            T* quest = task_.front();  // 被唤醒时，重新持有锁上锁，并继续运行
            task_.pop();
            //从任务队列取出后该解锁(任务队列锁)了
            lck.unlock();
            //执行任务后释放
            proc_(quest);
            // delete quest;   //在proc_已经释放该指针了
            //重新上锁
            lck.lock();
        }
    }
    std::mutex mutex_;     // 临界区资源，用于锁
    std::queue<T*> task_;  // 线程池任务队列
    std::condition_variable cv_;
    bool active_;  // 线程池是否工作
    std::vector<std::thread*> all_thread_;
    WorkerProc proc_;
};
#endif