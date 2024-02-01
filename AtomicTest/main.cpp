#include <iostream>
#include <atomic>
#include <utility>
#include <thread>
#include <mutex>

#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"

constexpr std::size_t ITERATION {10'000'000};
constexpr std::size_t ACCUMULATION_OF_1_DIGITS {9 * 10 / 2};
constexpr std::size_t TOTAL_VALUE {ACCUMULATION_OF_1_DIGITS * ITERATION};

template <typename T>
bool isLockFree(std::atomic<T> *val) {

    if(std::atomic_is_lock_free(val)) {
        std::cout << "Atomic is using lock-free mechanism for this type\n";
        return true;
    }
    std::cout << "Atomic is using non-lock-free mechanism for this type\n";
    return false;
}


void calculateUsingAtomic(std::atomic<std::size_t> &var) {
    
    while(true) {
        std::size_t value {var.load()};
        if(value >= TOTAL_VALUE) {
            break;
        }
        var.store(value + 1);
    }
}

void calculateUsingMutex(std::size_t &var, std::mutex &mut) {
    // std::lock_guard<std::mutex> lock {mut};
    std::unique_lock<std::mutex> mutex(mut, std::defer_lock);
    while(true) {
        // mutex.lock();
        std::lock_guard<std::mutex> lock {mut};
        if(var >= TOTAL_VALUE)
            break;
        ++var;
        // mutex.unlock();
    }
}

void calculateLockFree(std::size_t &var) {
    std::size_t sum {};
    while(sum < TOTAL_VALUE / 4) {
        ++sum;
    }
    var += sum;
}
 
int main()
{
    std::cout << "Total value: " << TOTAL_VALUE << "\n";
    constexpr size_t workerCount {4};

    std::vector<std::thread> workers;
    workers.reserve(workerCount);

    // std::atomic<std::size_t> value;

    std::vector<std::thread> workersArr(workerCount);

    TimeCounter t {};
    
    // for(size_t index {}; index < workerCount; ++index) {
    //     workers.emplace_back(calculateUsingAtomic, std::ref(value));
    // }

    std::size_t value {};
    // std::mutex mutex;
    // for(size_t index {}; index < workerCount; ++index) {
    //     workers.emplace_back(calculateUsingMutex, std::ref(value), std::ref(mutex));
    // }

    // for(auto &worker: workers) {
    //     worker.join();
    // }

    //this one slower than std::vector<std::thread>> approach because of destructor and join call at the end of the scope
    // join calls don't impact very much since the threads are independent
    for(size_t index {}; index < workerCount; ++index) {
        std::jthread {calculateLockFree, std::ref(value)};
    }

    // without optimizations lock-free thread usage 3.5x faster than plain for loop 
    // for(size_t index {}; index < workerCount; ++index) {
    //     calculateLockFree(value);
    // }

    // for(size_t index {}; index < workerCount; ++index) {
    //     workersArr[index] = std::thread {calculateLockFree, std::ref(value)};
    // }

    // for(size_t index {}; index < workerCount; ++index) {
    //     workersArr[index].join();
    // }

    // for(size_t index {}; index < workerCount; ++index) {
    //     workers.emplace_back(calculateLockFree, std::ref(value));
    // }

    // for(auto &worker: workers) {
    //     worker.join();
    // }

    t.timedelta();
    bool eq {TOTAL_VALUE == value};
    std::cout << "value : " << value << " and equality with total value: " << eq << "\n";

    

    return 0;
}