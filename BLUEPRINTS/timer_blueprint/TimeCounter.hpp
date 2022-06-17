#ifndef _TIME_COUNTER_HPP_
#define _TIME_COUNTER_HPP_

#include <iomanip>
#include <iostream>
#include <chrono>

using std::chrono::time_point;

// When the object is constructed, the timer starts.
struct TimeCounter {
    time_point<std::chrono::steady_clock> start, last_used;
    std::chrono::duration<double> duration;
    TimeCounter()
    : start {std::chrono::steady_clock::now()}, last_used {} {}

    // resets start point and last used point
    void restart_timer() {
        start = std::chrono::steady_clock::now();
        last_used = time_point<std::chrono::steady_clock> {};
    }

    // if restart_timer is not used before timedelta, then the timer counts the time from the construction moment
    void timedelta(std::ostream &out=std::cout) {
        last_used = std::chrono::steady_clock::now();
        duration = last_used - start;
        out << "Elapsed time: " << std::setprecision(8) << std::fixed 
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