#include "ThreadUtil.h"

#include <queue>
#include <mutex>
#include <atomic>
#include <future>
#include <thread>

typedef std::packaged_task<void()> QueuedWork;
static std::queue<QueuedWork> vm_run_queue;

static std::mutex vm_run_queue_mutex;

std::future<void> Mainloop::Next(std::function<void()> f)
{
    std::packaged_task<void()> task(f);
    auto fu = task.get_future();

    {
        std::lock_guard<std::mutex> guard(vm_run_queue_mutex);
        vm_run_queue.push(std::move(task));
    }

    return fu;
}

static std::atomic_bool mainloopThreadResolved(false);
static std::thread::id mainloopThreadId;

void Mainloop::Now(std::function<void()> f)
{
    if (!mainloopThreadResolved.load()) {
        // If you see this, don't run Now() inside plugin initializers. :)
        fprintf(stderr,
                "ERROR:\n"
                "ThreadUtil::Now() before game mainloop starts will deadlock.\n"
                "This is a problem with one of the plugins that uses Now()\n"
                "while no module is up yet.\n");
        abort();
    }

    if (mainloopThreadId == std::this_thread::get_id())
        f();

    else
        Next(f).wait();
}

void ThreadUtil_Mainloop_After()
{
    if (!mainloopThreadResolved.load()) {
        mainloopThreadId = std::this_thread::get_id();
        mainloopThreadResolved = true;
    }

    std::queue<QueuedWork> vm_this_queue;

    {
        std::lock_guard<std::mutex> guard(vm_run_queue_mutex);
        std::swap(vm_this_queue, vm_run_queue);
    }

    while (!vm_this_queue.empty()) {
        auto& f = vm_this_queue.front();
        f();
        vm_this_queue.pop();
    }
}
