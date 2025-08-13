#ifndef _ASYNC_TEST_
#define _ASYNC_TEST_

#include <thread>
#include <future>
#include <iostream>

namespace Promise {
    void setVar(std::future<int> &fut) {
        std::cout << "Waiting for the main thread to retrieve the value\n";
        std::cout << "Value: " << fut.get() << "\n";
    }
}

namespace PackagedTask {
    int setVar(int value) {
        std::cout << "returning the value from the runner thread\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return value;
    }
}


#endif