#include <iostream>     // std::cout, std::endl
#include <chrono>       // std::this_thread::sleep_for()
#include <thread>       // std::chrono::seconds()

struct mystruct {
    mystruct(double val = 0.0) {}
};

void func(int) {
    std::cout << 1 << "\n";
}

 void func(double) {
    std::cout << 2 << "\n";
}

void func(mystruct) {
    std::cout << 3 << "\n";
}

int main()
{
    // std::cout << "hello world";
    // std::this_thread::sleep_for(std::chrono::seconds(5));
    // std::cout << std::endl;

    if(true)
        func(1.1);
    else
        func(1);

    if(true)
        func(1.1);
    else
        func(mystruct {});

    return 0;
}