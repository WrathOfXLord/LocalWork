#include <iostream>
#include <algorithm>
#include "FunctorTest.hpp"


// class MultiplyByX;

template<typename type> void printArr(type arr[], size_t sz);

int main()
{
    //a simple instance of MultiplyBy, used as a simple object 
    // MultiplyBy init(5.5);
    // std::cout << "val : " << init(5) << "\n";
    //---------------
    double doubleArr[] {12, 32.3, 18, 1.2, 7.8};
    const size_t sizeArr {sizeof(doubleArr)/sizeof(double)};
    double result[sizeArr] {};
    std::transform(doubleArr, doubleArr + sizeArr, result, MultiplyBy(3));
    printArr(result, sizeArr);
    return 0;
}

// class MultiplyByX {
// private:
//     int val;
// public:
//     MultiplyByX(int val) : val {val} {}
//     int operator()(int other) const { return this->val * other; }
// };


template<typename type> void printArr(type arr[], size_t sz)
{
    for(size_t i {0}; i != sz; ++i) {
        std::cout << arr[i];
        if(i + 1 != sz)
            std::cout << ", ";
    }
    std::cout << "\n";
}