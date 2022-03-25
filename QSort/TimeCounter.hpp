#ifndef _TIME_COUNTER_HPP_
#define _TIME_COUNTER_HPP_

#include <iomanip>
#include <iostream>
#include <chrono>

using std::chrono::time_point;

struct TimeCounter {
    time_point<std::chrono::steady_clock> start;
    std::chrono::duration<double> duration;
    TimeCounter()
    : start {std::chrono::steady_clock::now()} {}

    void timedelta() {
        duration = std::chrono::steady_clock::now() - start;
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