#ifndef _MY_ITERATOR_HPP_
#define _MY_ITERATOR_HPP_

#include <iostream>

namespace My {
    using uint64_t = unsigned long long;
    template <typename type> class Iterator {
        using value_type = type;
        using pointer = type *;
        using reference = type &;
        using difference_type = std::ptrdiff_t;
        using Iterator_ref = Iterator<type> &;

    private:
        // pointer to point data
        pointer iterator;

    public:
        
        inline explicit Iterator(pointer iterable) : iterator {iterable} {}
        inline Iterator(const Iterator_ref other) : iterator {other.iterator} {}
        ~Iterator() = default;

        inline reference operator*() const { return *iterator; }
        inline auto operator==(const Iterator_ref rhs) const { return this->iterator == rhs.iterator; }
        inline auto operator!=(const Iterator_ref rhs) const { return !(this->iterator == rhs.iterator); }
        inline Iterator_ref operator++() { ++iterator; return *this; }
        inline Iterator operator++(int) { Iterator tmp {iterator}; ++iterator; return tmp; }
        inline Iterator_ref operator--() { --iterator; return *this; }
        inline Iterator operator--(int) { Iterator tmp{iterator}; --iterator; return tmp; }
        inline pointer operator->() { return iterator; }

        // extra functionality
        inline Iterator operator+(difference_type diff) { return Iterator {iterator + diff}; }
        inline Iterator operator-(difference_type diff) { return Iterator {iterator - diff}; }
        inline reference operator[](difference_type diff) { return iterator[diff]; }
    };
}

#endif