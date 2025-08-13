#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
// #include "TestClass.hpp"

using namespace std::chrono_literals;

enum Order {
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH,
    SIXTH,
};

const char* ORDER[] {
    "FIRST",
    "SECOND",
    "THIRD",
    "FOURTH",
    "FIFTH",
    "SIXTH"
};

std::atomic<int> counter = 0;

void inc(std::atomic<int> &a, Order order)
{
  while (a++ != 20) {
    printf("Increment from thread %.7s\n", ORDER[order]);
    printf("%d - value %d\n", ++counter, a.load());
    std::this_thread::sleep_for(100ms);
  }
}

int main()
{
  std::atomic<int> a {0};
  std::thread t1(inc, std::ref(a), FIRST);
  std::thread t2(inc, std::ref(a), SECOND);
  std::thread t3(inc, std::ref(a), THIRD);
  std::thread t4(inc, std::ref(a), FOURTH);
  std::thread t5(inc, std::ref(a), FIFTH);
  std::thread t6(inc, std::ref(a), SIXTH);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();

  std::printf("%d - val: %d\n", counter.load(), a.load());
  return 0;
}