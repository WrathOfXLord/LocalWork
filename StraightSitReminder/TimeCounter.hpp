#ifndef _TIME_COUNTER_HPP_
#define _TIME_COUNTER_HPP_

#include <iomanip>
#include <iostream>
#include <chrono>

template <typename DurationType>
    concept ValidDuration = std::is_same_v<DurationType, std::chrono::years> ||
                            std::is_same_v<DurationType, std::chrono::months> ||
                            std::is_same_v<DurationType, std::chrono::weeks> ||
                            std::is_same_v<DurationType, std::chrono::days> ||
                            std::is_same_v<DurationType, std::chrono::seconds> ||
                            std::is_same_v<DurationType, std::chrono::milliseconds> ||
                            std::is_same_v<DurationType, std::chrono::microseconds> ||
                            std::is_same_v<DurationType, std::chrono::nanoseconds>;

struct TimeCounter {
    using HRC = std::chrono::high_resolution_clock;
    using SC = std::chrono::steady_clock;
    using TimePoint = std::chrono::time_point<SC>;
    TimePoint last_used, start;
    std::chrono::duration<double> duration;
    TimeCounter()
    : last_used {}, start {SC::now()} {}

    // resets start point and last used point
    void restart_timer() {
        last_used = TimePoint {};
        start = SC::now();
    }

    // if restart_timer is not used before timedelta, then the timer counts the time from the construction moment
    void timedelta(bool outputRequested = true, std::ostream &out=std::cout) {
        last_used = SC::now();
        duration = last_used - start;
        if(outputRequested) {
            double time {static_cast<double>(timedelta_in<std::chrono::nanoseconds>()) * 1e-9};
            out << "Elapsed time: " << std::setprecision(8) << std::fixed 
            << time << std::scientific << " (" << std::setprecision(4)
            << time << ") seconds.\n" << std::fixed;
        }
    }
    

    void timedelta_in_nanos(bool outputRequested = true, std::ostream &out=std::cout) {
        last_used = SC::now();
        duration = last_used - start;
        if(outputRequested) {
            out << "Elapsed time: " << (last_used - start).count() << " nanoseconds\n";
        }
    }

    void captureTime() {
        last_used = SC::now();
        duration = last_used - start;
    }

    template <ValidDuration validDuration>
    int64_t timedelta_in() const {       
        return duration_cast<validDuration>(duration).count();
    }  
};

#endif