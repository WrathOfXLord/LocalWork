#include <iostream>
#include "BubbleSort.hpp"

int main() {

    int arr[] {3, 5, 73, 0, 9, 4, 27};
    std::size_t size {sizeof(arr) / sizeof(arr[0])};
    std::cout << "before sorting arr: ";
    Bubble::printArray(arr, size);
    Bubble::sort(arr, size);
    std::cout << "after sorting arr: ";
    Bubble::printArray(arr, size);
    return EXIT_SUCCESS;
}