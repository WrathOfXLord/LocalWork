#include "TemplateQSort_implement.hpp"
#include <iostream>
#include <string>
#include <clocale>
#include <array>
#include <cstring>
using clck = std::chrono::high_resolution_clock::time_point;

template<typename Type> void print(Type Arr[], size_t size);

int main()
{
    
    setlocale(LC_ALL, "Turkish");
    double arrStr[] {4.4, 5.8, 1.2, 3.3, 4.2};
    const size_t sizeArr {5};
    QSort(arrStr, 0, sizeArr - 1);
    print(arrStr, static_cast<long long>(sizeArr));
    RQSort(arrStr, 0, sizeArr - 1);
    print(arrStr, static_cast<long long>(sizeArr));
    std::cout << '\n';

    std::string container[] {"ali", "fırat", "yağmur", "gülsün", "miniş", "a", "b", "c", "d", "e", "f", "g", "h", "u", "i"};
    const size_t sizeCntnr {15};
    clck c1 {std::chrono::high_resolution_clock::now()};
    QSort(container, 0, sizeCntnr - 1);
    clck c2 {std::chrono::high_resolution_clock::now()};
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>((c2 - c1)).count() << '\n';
    print(container, static_cast<long long>(sizeCntnr));
    RQSort(container, 0, sizeCntnr - 1);
    print(container, static_cast<long long>(sizeCntnr));
    
    return 0;
}


template<typename Type> void print(Type Arr[], size_t size)
{
    std::cout << "Array = [ ";
    for(size_t i {}; i < size; ++i)
    {
        std::cout << "[" << Arr[i] << "]";
        if(i + 1 != size)
            std::cout << ", ";
    }
    std::cout << " ]\n";

}

