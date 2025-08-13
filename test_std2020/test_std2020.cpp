#include <iostream>
#include <numbers>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>
#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"

namespace My {
    //move
    template <typename T> void swap(T &x, T &y) { 
        T tmp {std::move(x)};
        // T tmp {x};
        x = std::move(y);
        y = std::move(tmp);
    }
    //copy
    // template <typename T> void swap(T &x, T &y) { 
    //     T tmp {x};
    //     x = y;
    //     y = tmp;
    // }
}

using TPoint = std::chrono::high_resolution_clock::time_point;

// using namespace numbers;
using namespace std;


std::vector<std::string_view> winnerList(const std::string_view *nameList, size_t size, size_t winnerCount) {
    if(winnerCount == 0)
        return std::vector<std::string_view> {};
    std::vector<std::string_view> list (winnerCount);
    int64_t seed{std::chrono::steady_clock::now().time_since_epoch().count()};
    std::mt19937_64 generator_engine{static_cast<size_t>(seed)};
    std::uniform_int_distribution<int64_t> dist{0, (int64_t)size - 1};
    int64_t first {dist(generator_engine)}, lastUsed {first};
    list[0] = nameList[first];
    for(size_t index {1}; index < winnerCount; ) {
        size_t index2 {};
        bool cmp {};
        lastUsed = dist(generator_engine);
        while(index2 < index) {
            cmp = list[index2] == nameList[lastUsed];
            if(cmp) {
                break;
            }
            ++index2;
        }
        if(!cmp) {
            list[index] = nameList[lastUsed];
            ++index;
        }
    }
    
    return list;
}

int main()
{
    // double x {pi};
    // std::cout << __cplusplus << std::endl;
    // cout << setprecision(10) << x << endl;
    // int a = 10, b = 3;
    // std::string a {"hey"}, b {"there"}, x;
    
    // TPoint time1 = std::chrono::high_resolution_clock::now();
    // for(size_t i {}; i < 5'000'001; ++i) {
    //     My::swap(a, b);
    //     // std::swap(a, b);
    // }
    // TPoint time2 = std::chrono::high_resolution_clock::now();

    // std::cout << "Timedelta: " << std::fixed << std::chrono::duration_cast<std::chrono::duration<double>>(time2 - time1).count() << " seconds.\n";
    // std::cout << "a: " << a << " b: " << b << '\n';
    // std::cout << "length of a: " << a.size() << "\n";
    // std::cout << "a: " << a << " b: " << b << "\n";

    // float x = 15;
    // printf("%10.1E", x);

    // int arr[4] {3, 4, 5};
    // std::cout << (arr + 2) << "\n";

    // std::string x {"hey there"};
    // std::string y {x, 2, 4};
    // std::cout << y << "\n";
    // y.insert(1, " ");
    // std::cout << y << "\n";

    // int a {5}, b {7};

    // int c = a++ + ++b;

    // std::cout << c << "\n";

    // std::vector<int> testVector {3, 4, 5, 62, 34, 21};
    // int arr[5] {3,4,5};
    // std::cout << arr << "\n" << arr + 5 << "\n";
    // std::cout << std::numbers::pi << "\n";
    // std::cout << "abc" << "\n" << " e\n";
    // std::cout << "abc" << "\n";

    std::string_view nameList[] {"ali", "merve", "nisa", "linda", "rahime"};
    size_t size {5}, winnerCount {3};
    TimeCounter t;
    std::vector<std::string_view> winners {winnerList(nameList, size, winnerCount)};
    t.timedelta();
    std::cout << "Winners:";
    for(const auto &e:winners) {
        std::cout << " " << e; 
    }
    std::cout << "\n";

    return 0;
}