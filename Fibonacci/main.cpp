#include "Fibonacci.hpp"

#include <iostream>
#include <chrono>
#include <iomanip>

using std::chrono::time_point;

struct TimeCounter {
    time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> duration;
    TimeCounter()
    : start {std::chrono::steady_clock::now()} {}

    ~TimeCounter() {
        end = std::chrono::steady_clock::now();
        duration = end - start;
        std::cout << "Elapsed time: " << duration.count() << " seconds." << "\n";
    }
    
};


int main(int argc, char *argv[]) {
    size_t val {45};
    // time_point t1 {std::chrono::steady_clock::now()};
    // size_t fib1 {Fibonacci::recursive(val)};
    // time_point t2 {std::chrono::steady_clock::now()};
    // size_t fib2 {Fibonacci::dynamic(val)};
    // time_point t3 {std::chrono::steady_clock::now()};
    // size_t fib3 {Fibonacci::spaceOptimized(val)};
    // time_point t4 {std::chrono::steady_clock::now()};

    // std::cout << std::fixed << std::setprecision(10);
    // std::cout << "Recursive (" << val << "): " << fib1 << ", Elapsed time: " <<
    //                     std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() <<" seconds\n";
    // std::cout << "Dynamic (" << val << "): " << fib2 << ", Elapsed time: " <<
    //                     std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2).count() <<" seconds\n";
    // std::cout << "Space optimized (" << val << "): " << fib3 << ", Elapsed time: " <<
    //                     std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2).count() <<" seconds\n";

    std::cout << "Recursive\n" << std::fixed << std::setprecision(11);
    {
        TimeCounter t1 {};
        Fibonacci::recursive(val);
    }
    std::cout << "Dynamic\n";
    {
        TimeCounter t2 {};
        Fibonacci::dynamic(val);
    }
    std::cout << "Space optimized\n";
    {
        TimeCounter t3 {};
        Fibonacci::spaceOptimized(val);
    }

    return EXIT_SUCCESS;
}