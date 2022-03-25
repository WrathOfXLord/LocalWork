#pragma once
#include <iostream>
#include <initializer_list>

namespace my {
    template <typename type, size_t size> class Array;
}

template<typename type, size_t size> class my::Array {
    friend std::ostream &operator<<(std::ostream &os, const Array &rhs)
    {
        if(rhs.len == 0) {
            std::cerr << "Empty container\n";
            return os;
        }
        os << " [ ";
        for(size_t i {}; i < rhs.len; ++i) {
            os << rhs.arr[i];
            if(i + 1 != rhs.len)
                os << ", ";
        }
        os << " ] ";
        return os;
    }
private:
    size_t len;
    type arr[size];
public:
    Array() : len {size}, arr {} {}

    template <typename ...T> Array(T &&...args): len {size}, arr {std::forward<T>(args)...} {};
    // Array(std::initializer_list<type> &&pack) : len {pack.size()} { std::forward<type *>(std::copy(pack.begin(), pack.end(), arr)); }
    size_t length() const { return this->len; }
};

