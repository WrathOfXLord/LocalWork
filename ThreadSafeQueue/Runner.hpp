#pragma once

#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include <sstream>

namespace LinkedListTest {
    void run(bool runRequested) {
        if(!runRequested) {
            return;
        }

        LinkedList<int> myList {};

        myList.push(3);
        myList.push(4);
        myList.push(17);
        myList.push(46);
        myList.push(47);
        myList.push(1618);

        // std::cout << "Please enter a number between -32768 and 32767: ";
        // std::string buff;
        // buff.reserve(32);
        // std::cin >> buff;
        // std::stringstream userInputProcess {buff};
        // short userVal {};
        // if(!(userInputProcess >> userVal)) {
        //     throw std::runtime_error("Invalid Input!");
        // }
        // myList.push(static_cast<int>(userVal));

        std::cout << "back: " << myList.back() << "\n";
        std::cout << "front: " << myList.front() << "\n";
        std::cout << "List: " << myList << "\n";
        myList.pop();
        std::cout << "back: " << myList.back() << "\n";
        std::cout << "front: " << myList.front() << "\n";
        std::cout << "List: " << myList << "\n";
        auto &frontRef {myList.front()};
        
        frontRef = 32;
        std::cout << myList << "\n";
        
        std::cout << "\n";
    }
}