#include <iostream>
#include <chrono>
#include <iomanip>
#include "Number.hpp"

using tp = std::chrono::high_resolution_clock::time_point;

int main()
{
    Number n1 {4};
    tp t1 {std::chrono::high_resolution_clock::now()};
    std::cout << std::setprecision(15) << n1.root(2, 341213) << " \n";
    tp t2 {std::chrono::high_resolution_clock::now()};
    std::cout << "elapsed time : " << std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count() << "\n";
}