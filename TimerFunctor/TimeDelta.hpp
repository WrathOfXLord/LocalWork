#ifndef _TIME_DELTA_HPP_
#define _TIME_DELTA_HPP_

#include <iostream>
#include <chrono>

class TimeDelta {
    using duration = std::chrono::high_resolution_clock::duration;
    friend std::ostream &operator<<(std::ostream &os, TimeDelta &rhs) {
        if(!rhs.timeGiven) {
            os << "No time points were given";
            return os;
        }
        os << "hh:mm:ss : " << rhs.hours << ":" << rhs.minutes << ":" << rhs.seconds;
        return os;
    }

private:
    duration start;
    duration end;
    long long delta;
    int seconds;
    int minutes;
    int hours;
    bool timeGiven;
public:

    TimeDelta() : start {}, end {}, delta {}, seconds {}, minutes {}, hours {}, timeGiven {0} {}

    long double operator()(duration &start, duration &end) {
        this->start = start;
        this->end = end;
        delta = static_cast<long long>(std::chrono::duration_cast<std::chrono::duration<long double>>(end - start).count());
        seconds = delta % 60;
        minutes = delta / 60;
        hours = delta / 3600;
        timeGiven = 1;
        std::cout << *this << "\n";
        return std::chrono::duration_cast<std::chrono::duration<long double>>(end - start).count();
    }
    
};

#endif