#include <iostream>
#include "qsort.hpp"

int main() {
    
    constexpr const size_t size {14};
    int arr[size] {3, 21, 543, 32, 2, 43, 6, 66, 68, 25, 33, 47, 1, 5};

    Sort::quicksort<int>(arr, 0, size - 1);

    for(size_t index {}; index < size; ++index)
        std::cout << arr[index] << " ";
    std::cout << "\n";
    return EXIT_SUCCESS;
}