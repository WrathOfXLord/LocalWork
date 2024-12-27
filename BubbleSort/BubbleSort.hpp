#ifndef __B_SORT_HPP__
#define __B_SORT_HPP__

#include <algorithm>

struct Bubble {
 private:
    using sizeType = decltype(sizeof(0));
 public:
    template <typename T>
    static void sort(T values[], sizeType size) {
        if(size < 2) {
            return;
        }
        sizeType lastIndex {size - 1};
        for(sizeType outIt {0}; outIt < size; ++outIt) {
            for(sizeType innIt {0}; innIt < lastIndex - outIt; ++innIt) {
                if(values[innIt] > values[innIt + 1]) {
                    std::swap(values[innIt], values[innIt + 1]);
                }
            }
        }
    }
    
    template <typename T>
    static void printArray(T values[], size_t size) {
        std::cout << "| ";
        for(size_t i {}; i < size; ++i) {
            std::cout << values[i] << " ";
        }
        std::cout << "|";
    }
};

#endif