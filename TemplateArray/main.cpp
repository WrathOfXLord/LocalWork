#include <iostream>
#include "TemplateArray_implement.hpp"
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
#include <iomanip>

using hrc = std::chrono::high_resolution_clock;
using time_point = std::chrono::high_resolution_clock::time_point;


int main()
{
    Array<int, 8> newArr {5, 6, 7, 1, 34, 11, 3, 18};
    std::cout << newArr << "\n" << "size is: " << newArr.size() << "\n";
    std::cout << *(newArr.end() - 3) << "\n";
    std::cout << newArr[4] << '\n';
    Array<int, 8>::CustomIterator custom_ite {};
    custom_ite = newArr.begin();
    std::sort(newArr.begin(), newArr.end(), std::greater<>());
    std::cout << newArr << "\n";

    // time_point start {hrc::now()};
    // for (size_t i = 0; i < 1000; ++i)
    // {
    //     Array<int, 20> newArr2 {5, 6, 7, 1, 34, 11, 3, 18, 3, 4, 12, 32};
    // }
    // time_point end {hrc::now()};

    // std::cout << "elapsed time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count() << "\n";
    
    
    // std::array<int, 3> arr2 {3, 4, 5};
    // std::cout << arr2[1] << "\n";

    return 0;
}