#include <iostream>
#include <string>
#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"


// auto test() -> int {

// }

inline int64_t flipBit(int64_t number, int64_t indexOfBit) {
    return number ^ (1 << indexOfBit);
}

int64_t makeEqualBitByBit(int64_t number1, int64_t &number2, const int64_t MAX_BIT_COUNT = 64) {
    for(int64_t index {}; index != MAX_BIT_COUNT; ++index) {
        int64_t mask1 {number1 & 1 << index};
        int64_t mask2 {number2 & 1 << index};
        if(mask1 != mask2) {
            // TimeCounter t {};
            number2 = flipBit(number2, index);
            // number2 ^= 1 << index;
            // t.timedelta();   
        }
    }
    
    return number2;
}

template <typename type>
int binarySearchAscendingOrder(type *arr, int startIndex, int endIndex, type value) {
    if(endIndex < startIndex || startIndex < 0)
        return -1;
    int mid {startIndex + (endIndex - startIndex) / 2};

    if(arr[mid] == value)
        return mid;

    if(arr[mid] <= value)
        return binarySearchAscendingOrder(arr, mid + 1, endIndex, value);
    
    return binarySearchAscendingOrder(arr, startIndex, mid - 1, value);
}

template <typename T>
int iterativeBinarySearch(T *arr, int startIndex, int endIndex, T value) {
    if(endIndex < startIndex || startIndex < 0)
        return -2;
    
    int mid {};
    while(endIndex >= startIndex) {
        mid = startIndex + (endIndex - startIndex) / 2;
        if(arr[mid] == value)
            return mid;
        
        if(value > arr[mid]) {
            startIndex = mid + 1;
        } else {
            endIndex = mid - 1;
        }
    }
    
    return -1;
}

template <typename type>
int linearSearchAscendingOrder(type *arr, int startIndex, int endIndex, type value) {
    if(endIndex < startIndex || startIndex < 0)
        return -1;
    for(; startIndex <= endIndex; ++startIndex) {
        if(arr[startIndex] == value)
            return startIndex;
    }
    return -1;
}

int main()
{
    // int64_t number1 {10}, number2 {7};

    // TimeCounter t {};
    // makeEqualBitByBit(number1, number2);
    // t.timedelta();
    
    // std::cout << "number2: " << number2 << "\n";
    int size {1000000};
    int *arr {new int[size]};
    for(int index {999990}, values {1}; index != 1000000; ++index, ++values) {
        arr[index] = values;
    }
    std::cout << "array's last element is " << arr[999999] << "\n"; 
    int index {};
    TimeCounter t {};
    // index = linearSearchAscendingOrder(arr, 0, size - 1, 7);
    index = binarySearchAscendingOrder(arr, 0, size - 1, 7);
    // index = iterativeBinarySearch(arr, 0, size - 1, 7);
    t.timedelta();
    std::cout << "index: " << index << "\n";
    delete [] arr;

    // std::string_view myView {"hey there"};
    // std::string strCreated {};
    // std::cout << "size of str: " << strCreated.size() << ", str: " << strCreated << "\n";
    // strCreated = myView;
    // std::cout << "after assigning size of str: " << strCreated.size() << ", str: " << strCreated << "\n";
    // std::cout << "str data ptr: " << (void *)strCreated.data() << ", view data ptr: " << (void *)myView.data() << "\n";
    // or
    // std::printf("str data ptr: %p, view data ptr: %p \n", strCreated.data(), myView.data());
    // std::printf("str data: %s, view data: %s \n", strCreated.data(), myView.data());

    return EXIT_SUCCESS;
}

