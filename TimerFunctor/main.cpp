#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "TimeDelta.hpp"


using duration = std::chrono::high_resolution_clock::duration;

int main()
{   
    duration start {std::chrono::high_resolution_clock::now().time_since_epoch()};
    //doing some stuff
    std::string input {};
    std::stringstream ss;
    int someValue {};
    bool readDone {0};

    do {
        std::cout << "Enter a Valid Value\n";
        std::cin >> std::setw(5) >> input;
        std::cout << "input : " << input << "\n\n"; 
        ss = std::stringstream {input};
        if(ss >> someValue) {
            readDone = !readDone;
            std::cout << "Read Succeed\n" << "Val: " << someValue << "\n\n";
        } else {
            std::cout << "Read Failed\n";
        }
    } while(!readDone);

    duration end {std::chrono::high_resolution_clock::now().time_since_epoch()};
    
    TimeDelta delta {};
    std::cout << "\n" << delta(start, end) << "\n";
    
    return 0;
}