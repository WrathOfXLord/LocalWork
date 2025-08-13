#include <iostream>
#include <vector>
#include "Test.h"

#include "../BLUEPRINTS/Search/Search.hpp"
#include "../BLUEPRINTS/Sort/Sort.hpp"

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
    if(vec.size() == 0)
        return out;
    for(const auto &e: vec) {
        out << "|" << e;
    }
    return out << "|";
}

int main()
{
    // MyTestClass t1 {
    //     {"Test Name1", Type::Float},
    //     {"Test Name2", Type::Int},
    //     {"Test Name3", Type::Bool}
    // };

    // std::cout << "name: " << t1[0].name << "\n";

    // int arr[] {3, 5, 6, 8, 12, 13, 18, 25, 28, 32, 37, 40, 235, 331, 487};
    // int arrLen {sizeof(arr) / sizeof(arr[0])};

    // std::cout << "arr length: " << arrLen << "\n";

    // int index {Search::binSearchBySize(37, arr, arrLen)};

    // std::cout << "index: " << index << "\n";

    std::vector<int> numList {3, 5, 6, 8, 12, 13, 18, 25, 28, 32, 37, 40, 235, 331, 487};

    int value {235};
    int index {Search::binSearchBySize(value, numList.data(), numList.size())};
    std::cout << "Element " << value << " found at index: " 
                            << index
                            << " (-1 if not found)\n";

    std::cout << "Element: " << numList.at(index) << "\n";

    std::vector<int> unsorted {13, 5, 6, 8, 1, 6, 18, 25, 56, 28, 32, 37, 40, 25, 33, 487, 56, 38};

    std::cout << "vector before sorting: " << unsorted << "\n";
    Sort::quicksort(unsorted.data(), 0, unsorted.size() - 1);
    std::cout << "vector after sorting: " << unsorted << "\n";
    
    
    return 0;
}