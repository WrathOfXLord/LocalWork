#include <iostream>
#include <thread>
#include <chrono>

using std::literals::chrono_literals::operator""ms;

void foo(int &x) {
    while(true) {
        try
        {
            std::cout << x << "\n";
            std::this_thread::sleep_for(1000ms);
        } catch(...) {
            throw std::runtime_error("this is a runtime error!");
        }
        
    }
}

void bar() {
    int x {5};
    std::thread thread2 {foo, std::ref(x)};
    thread2.detach();
    std::this_thread::sleep_for(5000ms);
    std::cout << "thread1 finished execution\n";
}

void run() {
    std::thread t1 {[]() {
        // std::this_thread::sleep_for(1200ms);
        std::cout << "Hello from lambda t1\n";
    }};

    std::thread t2 {std::move(t1)};

    t1 = std::thread{[]() {
        // std::this_thread::sleep_for(1100ms);
        std::cout << "Newly reconstructed t2\n";
    }};

    std::thread t3 {[]() {
        // std::this_thread::sleep_for(1000ms);
        std::cout << "Hello from lambda t3\n";
    }};

    std::cout << "Test\n";
    t1.join();
    
    t1 = std::move(t3);
    if(t1.joinable())
        t1.join();
    else
        std::cout << "Not joinable\n";
    t2.join();
    // t3.join();


}

int main() {
    // std::thread t {bar};
    // t.join();

    // run();

    constexpr auto &allowedThreads = std::thread::hardware_concurrency;
    std::cout << "logical core count: " << allowedThreads() << "\n";

    return 0;
}