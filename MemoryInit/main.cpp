#include <iostream>
#include <chrono>

using hrc = std::chrono::high_resolution_clock;
using time_point = std::chrono::high_resolution_clock::time_point;
using intptr = int *;

int main() 
{
    intptr ptr {};

    time_point start {hrc::now()};
    //test case 1 elapsed time = 0.0006942
    // ptr = new int[5000]();
    // std::cout << "ptr[12] : " << ptr[12] << "\n";
    // delete [] ptr;

    //test case 2 elapsed time = 0.0007923
    // ptr = new int[5000] {};
    // std::cout << "ptr[12] : " << ptr[12] << "\n";
    // delete [] ptr;

    //test case 3 elapsed time = 0.0008788
    ptr = (intptr) std::calloc(5000, sizeof(int));
    std::cout << "ptr[12] : " << ptr[12] << "\n";
    std::free(ptr);
    
    ptr = nullptr;

    time_point end {hrc::now()};

    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count() << "\n";

    return 0;
}