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


int main()
{
    // double x {pi};
    // std::cout << __cplusplus << std::endl;
    // cout << setprecision(10) << x << endl;
    // int a = 10, b = 3;
    std::string a {"hey"}, b {"there"}, x;
    
    TPoint time1 = std::chrono::high_resolution_clock::now();
    for(size_t i {}; i < 5'000'001; ++i) {
        My::swap(a, b);
        // std::swap(a, b);
    }
    TPoint time2 = std::chrono::high_resolution_clock::now();

    std::cout << "Timedelta: " << std::fixed << std::chrono::duration_cast<std::chrono::duration<double>>(time2 - time1).count() << " seconds.\n";
    std::cout << "a: " << a << " b: " << b << '\n';
    std::cout << "length of a: " << a.size() << "\n";
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
    return 0;
}