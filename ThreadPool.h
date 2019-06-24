#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <list>
#include <functional>
#include <thread>

class ThreadPool
{
private:
    /* data */
public:
    using Task = std::function<void()>;
    ThreadPool(/* args */)=delete;
    ThreadPool(int nums);
    ~ThreadPool();

    void addTask(Task &&task);

    void worker();
    

    bool quited;
    std::mutex mtx;
    
    std::condition_variable cond;
    std::list<std::thread> threads;
    std::vector<Task> tasks;

};

ThreadPool::ThreadPool(int nums):quited(false)
{
    for (size_t i = 0; i < nums; i++)
    {
        threads.emplace_back(std::bind(&ThreadPool::worker,this));
    }
    
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(mtx);
        quited = true;
    }
    cond.notify_all();
    for (auto& t : threads)
    {
        t.join();
    }

}

void ThreadPool::addTask(Task &&task)
{
    {
         std::unique_lock<std::mutex> lck(mtx);
         tasks.emplace_back(task);
    }
   
    cond.notify_one();

}

void ThreadPool::worker()
{
    std::cout << "Create Worker Thread: " << std::this_thread::get_id() << std::endl;
    while (!quited)
    {
        std::vector<std::function<void()>> task_tmp;
        
        {
            std::unique_lock<std::mutex> lck(mtx);
            cond.wait(lck);
            task_tmp.swap(tasks);
        }

        for (int i = 0; i < task_tmp.size(); i++)
        {
            task_tmp[i]();
        }
        
    }

    std::cout << "quite Worker Thread: " << std::this_thread::get_id() << std::endl;
    
 
}
