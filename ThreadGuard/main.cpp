#include <iostream>
#include <thread>

class ThreadGuard {
private:
    std::thread &mThread;
public:
    explicit ThreadGuard(std::thread &thread) : mThread {thread} {}

    ~ThreadGuard() {
        if(mThread.joinable()) {
            mThread.join();
        }
    }

    ThreadGuard(const ThreadGuard &) = delete;
    ThreadGuard & operator=(const ThreadGuard &) = delete;
};

void foo() {
    std::cout << "Hello from foo!\n";
}

void unsafeOperations() {
    std::cout << "Runtime error has just been thrown.\n";
    throw std::runtime_error("Unsafe Operation!");
}

int main() {

    std::thread tFoo {foo};
    ThreadGuard tgFoo {tFoo};
    try
    {
        unsafeOperations();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << ": fixed.\n";
    }
    tFoo.join();
    
    

    return 0;
}