#ifndef _TIME_COUNTER_HPP_
#define _TIME_COUNTER_HPP_

#include <iomanip>
#include <iostream>
#include <chrono>

using std::chrono::time_point;

struct TimeCounter {
    time_point<std::chrono::steady_clock> start, last_used;
    std::chrono::duration<double> duration;
    TimeCounter()
    : start {std::chrono::steady_clock::now()}, last_used {} {}

    void restart_timer() {
        start = std::chrono::steady_clock::now();
        last_used = time_point<std::chrono::steady_clock> {};
    }

    void timedelta() {
        last_used = std::chrono::steady_clock::now();
        duration = last_used - start;
        std::cout << "Elapsed time: " << std::setprecision(8) << std::fixed 
            << duration.count() << std::scientific << " (" << std::setprecision(4)
            << duration.count() << ") seconds." << "\n";
    }

    // not a good way to measure elapsed time
    // ~TimeCounter() {
    //     end = std::chrono::steady_clock::now();
    //     duration = end - start;
    //     std::cout << "Elapsed time: " << std::setprecision(8) << std::fixed 
    //                             << duration.count() << " seconds." << "\n";
    // }
    
};

#endif