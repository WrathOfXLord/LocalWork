#ifndef _FIBONACCI_HPP_
#define _FIBONACCI_HPP_

using size_t = unsigned long long;

class Fibonacci {
public:
    static size_t recursive(size_t index) {
        if(index <= 1)
            return index;
        return recursive(index - 1) + recursive(index - 2);
    }

    static size_t dynamic(size_t index) {
        if(index <= 1)
            return index;
        size_t fibArray[index + 1];
        fibArray[0] = 0;    fibArray[1] = 1;
        for(size_t at {2}; at <= index; ++at) {
            fibArray[at] = fibArray[at - 1] + fibArray[at - 2];
        }
        return fibArray[index];
    }

    static size_t spaceOptimized(size_t index) {
        if(index <= 1)
            return index;
        size_t old2 {0}, old1 {1}, current {1};
        for(size_t e {3}; e <= index; ++e) {
            old2 = old1;
            old1 = current;
            current = old1 + old2;
        }
        return current;
    }
};

#endif