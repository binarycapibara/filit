// curl'ed from https://github.com/progschj/ThreadPool
// 9a42ec1329f259a5f4881a291db1dcb8f2ad9040
// Edit1: added ThreadPool::getWorkers()
// Edit2: added a progress print

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

using namespace std::literals;

class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
        -> std::future<typename std::result_of<F(Args...)>::type>;
	std::vector< std::thread > const &getWorkers() const;
    ~ThreadPool();
private:
    // need to keep track of threads so we can join them
    std::vector< std::thread > workers;
    // the task queue
    std::queue< std::function<void()> > tasks;
	std::chrono::system_clock::time_point last_report;
    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;

    bool stop;
};

inline std::vector< std::thread > const &ThreadPool::getWorkers() const
{
	return this->workers;
}

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
    :   last_report(std::chrono::system_clock::now()), stop(false)
{
    for(size_t i = 0;i<threads;++i)
        workers.emplace_back(
            [this]
            {
                for(;;)
                {
                    std::function<void()> task;
					int nleft;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock,
                            [this]{ return this->stop || !this->tasks.empty(); });
                        if(this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
						nleft = this->tasks.size();
						if (std::chrono::system_clock::now() - this->last_report > 250ms)
						{
							std::cout << "                    \r";
							std::cout  << nleft << " tasks left";
							std::cout.flush();
							this->last_report = std::chrono::system_clock::now();
						}
                    }
                    task();
                }
            }
        );
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // don't allow enqueueing after stopping the pool
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task](){ (*task)(); });
    }
    condition.notify_one();
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(std::thread &worker: workers)
        worker.join();
}

#endif
