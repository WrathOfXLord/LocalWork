#include <iostream>
#include <array>
#include "qsort.hpp"
#include "TimeCounter.hpp"
#include <list>

template<typename type>
void printCollection(const type *data, size_t size) {
    for(size_t index {}; index != size; ++index) {
        std::cout << data[index] << " ";
    }
    std::cout << "\n";
}

int main() {
    
    // constexpr const size_t size {14};
    // int arr[size] {3, 21, 543, 32, 2, 43, 6, 66, 68, 25, 33, 47, 1, 5};

    // Sort::quicksort<int>(arr, 0, size);


    std::array<std::string_view, 6> str {"hey","there", "qwert", "asdf", "master", "work"};
    std::cout << "before sorting : ";
    printCollection(str.data(), str.size());
    {
        TimeCounter t1 {};
        Sort<std::string_view>::quicksort(str.data(), 0, str.size());
        t1.timedelta();
    }

    std::list<int> lst {3, 4, 5, 6};
    std::list<int>::iterator ite {lst.begin()};
    *(++ite) = 3;
    std::cout << *lst.begin() << "\n";
    
    std::cout << "after sorting : ";
    printCollection(str.data(), str.size());
    return EXIT_SUCCESS;
}