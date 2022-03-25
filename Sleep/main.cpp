#include <iostream>     // std::cout, std::endl
#include <chrono>       // std::this_thread::sleep_for()
#include <thread>       // std::chrono::seconds()

int main()
{
    std::cout << "hello world";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << std::endl;

    return 0;
}