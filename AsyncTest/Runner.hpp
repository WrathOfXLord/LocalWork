#ifndef _T_RUNNER_
#define _T_RUNNER_

#include "Promise.hpp"
#include "PromiseExcept.hpp"
#include "SharedFuture.hpp"

    namespace PackagedTask {
        void run(bool runRequested) {
            if(!runRequested)
                return;
            std::packaged_task<int(int)> packagedTask {setVar};
            std::future<int> taskFut {packagedTask.get_future()};
            std::thread runnerThread {std::move(packagedTask), 47};
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            std::cout << "Waiting for the runner thread to retrieve the value\n";
            std::cout << "Value: " << taskFut.get() << "\n";
            runnerThread.join();
        }
    }

    namespace Promise {
        void run(bool runRequested) {
            if(!runRequested)
                return;
            std::promise<int> p;
            
            auto taskFuture {p.get_future()};
            std::thread runnerThread {setVar, std::ref(taskFuture)};

            std::cout << "setting the value in the main thread\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            p.set_value(47);
            runnerThread.join();
            
        }
    }

    namespace PromiseExcept {
        void run(bool runRequested) {
            if(!runRequested)
                return;
            std::promise<int> prom;
            std::future<int> promFut {prom.get_future()};
            std::thread printerThread {printResult, std::ref(promFut)};
            std::thread calculatorThread {calculateSqrt, std::ref(prom)};

            printerThread.join();
            calculatorThread.join();
        }
    }

    namespace SharedFuture {
        void run(bool runRequested) {
            if(!runRequested)
                return;
            std::promise<int> promisedValue;
            std::shared_future<int> promiseFut {promisedValue.get_future()};

            std::thread t1 {printResult, std::ref(promiseFut)};
            std::thread t2 {printResult, std::ref(promiseFut)};

            promisedValue.set_value(5);
            
            t1.join();
            t2.join();
        }
    }

#endif