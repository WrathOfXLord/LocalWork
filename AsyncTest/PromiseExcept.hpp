#ifndef _PROM_EXCEPT_
#define _PROM_EXCEPT_

#include <thread>
#include <future>
#include <iostream>
#include <stdexcept>
#include <cmath>

    namespace PromiseExcept {
        void throwExcept() {
            throw std::runtime_error("Value cannot be negative!");
        }

        void calculateSqrt(std::promise<int> &prom) {
            std::cout << "Please enter an integer greater than 0: ";
            int value;
            try {
                std::cin >> value;
                if(value < 0) {
                    throwExcept();
                }
                prom.set_value(std::sqrt(value));
            } catch (...) {
                std::cout << "An exception caught with thread: " << std::this_thread::get_id() << "\n";
                prom.set_exception(std::current_exception());
            }
        }

        void printResult(std::future<int> &fut) {
            try {
                int value {fut.get()};
                std::cout << "value: " << value << "\n";
            } catch(const std::exception& e) {
                std::cerr << "[Exception caught: " << e.what() << "] - ThreadId: " << std::this_thread::get_id() << "\n";
            }
            
        }
    }

#endif