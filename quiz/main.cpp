#include <iostream>
#include <functional>
#include <chrono>
#include <future>
#include <queue>

// A structure to represent a delayed task
struct DelayedTask {
    std::function<void()> task;
    std::chrono::steady_clock::time_point executeAt;
};

// A simple "event loop" to handle deferred tasks on a single thread
class EventLoop {
public:
    void setTimeout(std::function<void()> callback, int delay_ms) {
        DelayedTask delayedTask{
            callback, 
            std::chrono::steady_clock::now() + std::chrono::milliseconds(delay_ms)
        };
        tasks.push(delayedTask);
    }

    void run() {
        while (!tasks.empty()) {
            auto now = std::chrono::steady_clock::now();

            if (now >= tasks.top().executeAt) {
                tasks.top().task();  // Run the task
                tasks.pop();         // Remove the completed task
            } else {
                // Simulate non-blocking waiting by yielding control briefly
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
    }

private:
    // Priority queue to execute tasks in the order of their scheduled time
    struct Compare {
        bool operator()(const DelayedTask& a, const DelayedTask& b) {
            return a.executeAt > b.executeAt;
        }
    };
    std::priority_queue<DelayedTask, std::vector<DelayedTask>, Compare> tasks;
};

int main() {
    EventLoop loop;

    std::cout << "Testing\n";
    // Schedule an async "single-threaded" callback
    loop.setTimeout([]() {
        std::cout << "Async task completed after delay!\n";
    }, 3000);

    std::cout << "Doing other work in main...\n";
    
    // Run the event loop
    loop.run();

    std::cout << "Finished other work in main.\n";
    return 0;
}