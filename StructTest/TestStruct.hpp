#ifndef _TEST_STRUCT_HPP
#define _TEST_STRUCT_HPP

#include "IteratorTemplate.hpp"
#include <iostream>
#include <string>

template <size_t val>
struct AnyStruct {
    std::string_view name;
    std::string_view arr[val];
    size_t size() const { return val; }

    AnyStruct() : name {"No Name"}, arr {} {};
    AnyStruct(const std::string_view &name, const std::string_view arr[], size_t arr_size) : name {name}, arr {} {
        size_t lesserLength {std::min(val, arr_size)};
        for(size_t index {}; index != lesserLength; ++index) {
            this->arr[index] = arr[index];
        }
    }

    My::Iterator<std::string_view> begin() { return My::Iterator {arr}; };
    My::Iterator<std::string_view> end() { return My::Iterator {&arr[val]}; };
};

#endif