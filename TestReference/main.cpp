#include <iostream>
#include <string>
#include <future>

int main() {

  size_t val {};
  
  [[maybe_unused]] int a = std::async(std::launch::async, [&val]() {
    std::printf("test3\n");
    for(size_t i {0}; i < 10'000'000'000; ++i) {
      val = i;
    }

    std::printf("test1\n");
    return 0;
  }).get();

  char x {};
  
  [[maybe_unused]] int b = std::async(std::launch::deferred, [&x]() {
    std::printf("test4\n");
    for(char ch {'a'}; ch <= 'z'; ++ch) {
      x = ch;
    }

    std::printf("test2\n");
    return 0;
  }).get();
  
}