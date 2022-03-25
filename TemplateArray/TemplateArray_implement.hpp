#ifndef _TEMPLATEARRAY_IMPLEMENT_HPP_
#define _TEMPLATEARRAY_IMPLEMENT_HPP_
// #include "TemplateIterator_implement.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <initializer_list>


template<typename any, size_t Size>
class Array {
    friend std::ostream &operator<<(std::ostream &outStream, Array &rhs)
    {
        outStream << "[";
        for(size_t i {}; i < rhs.arrSize; ++i)
        {
            outStream << "[" << rhs[i] << "]";
            if(i + 1 != rhs.arrSize)
                outStream << ", ";
        }
        outStream << "]";
        return outStream;
    }
private:
    const size_t arrSize {Size};
    any arr[Size];

public:

    class CustomIterator;

    Array() : arr {any {}} {};
    explicit Array(any val);
    template<typename ... any_> Array(any &&arg1, any_ &&...args);

    any &operator[](size_t index);

    inline size_t size() const { return this->arrSize; }
    inline CustomIterator begin() { return CustomIterator {this->arr}; }
    inline CustomIterator end() { return CustomIterator {this->arr + this->arrSize}; }
    
};


template<typename any, size_t Size> class Array<any, Size>::CustomIterator {
    
    friend CustomIterator operator+(int lhs, const CustomIterator &rhs)
    {
        return CustomIterator {rhs.ite + lhs};
    }

private:
    any *ite;
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = any;
    using reference = any&;
    using pointer = any*;
    using difference_type = std::ptrdiff_t;
    //explicit CustomIterator() : ite {nullptr} {}
    explicit CustomIterator(any *ptr = nullptr) : ite {ptr} {}
    ~CustomIterator() = default;
    bool operator<(const CustomIterator &rhs) const;
    bool operator<=(const CustomIterator &rhs) const;
    bool operator>(const CustomIterator &rhs) const;
    bool operator>=(const CustomIterator &rhs) const;
    bool operator==(const CustomIterator &rhs) const;
    bool operator!=(const CustomIterator &rhs) const;
    reference operator*() const;    //we need to return any reference if we want to use it in foreach loop
    //because if we only return any then it returns only rvalue which cannot be used 
    //referenced for loop something like this: for(auto &x:container)
    //initial value of reference to non-const must be an lvalue but container in the foreach loop returns rvalue without the reference
    //when it dereferenced by foreach loop
            
    pointer operator->();
    reference operator[](std::size_t index);
    CustomIterator &operator+=(const difference_type &rhs);
    CustomIterator &operator-=(const difference_type &rhs);
    CustomIterator &operator++();
    CustomIterator operator++(int);
    CustomIterator &operator--();
    CustomIterator operator--(int);
    CustomIterator operator+(const difference_type &rhs) const;
    CustomIterator operator-(const difference_type &rhs) const;
    difference_type operator-(const CustomIterator &rhs) const;
};



template<typename any, size_t Size> Array<any, Size>::Array(any val)
{
    for(any &traverse : *this)
        traverse = val;
}

template<typename any, size_t Size> template<typename ... any_> Array<any, Size>::Array(any &&arg1, any_ &&...args)
: arr {arg1, args...}
{
    
}

template<typename any, size_t Size> any &Array<any, Size>::operator[](size_t index)
{
    if(index >= arrSize || index < 0)
        throw OutOfBoundsException {};
    return this->arr[index];
}

template<typename any, size_t Size>
bool Array<any, Size>::CustomIterator::operator<(const CustomIterator &rhs) const
{
    return *(*this) < *rhs;
}

template<typename any, size_t Size>
bool Array<any, Size>::CustomIterator::operator<=(const CustomIterator &rhs) const
{
    return *(*this) <= *rhs;
}

template<typename any, size_t Size>
bool Array<any, Size>::CustomIterator::operator>(const CustomIterator &rhs) const
{
    return *(*this) > *rhs;
}

template<typename any, size_t Size>
bool Array<any, Size>::CustomIterator::operator>=(const CustomIterator &rhs) const
{
    return *(*this) >= *rhs;
}

template<typename any, size_t Size>
bool Array<any, Size>::CustomIterator::operator==(const CustomIterator &rhs) const
{
    //*this , dereferences the current object 
    //but *(*this) firstly dereferences the current object then with overloaded * operator, dereferences this->ite
    return *(*this) == *rhs;
}

template<typename any, size_t Size>
bool Array<any, Size>::CustomIterator::operator!=(const CustomIterator &rhs) const
{
    return !(*(*this) == *rhs);
}

template<typename any, size_t Size>
any &Array<any, Size>::CustomIterator::operator*() const
{
    return *(this->ite);
}

template<typename any, size_t Size>
any *Array<any, Size>::CustomIterator::operator->()
{
    return this->ite;
}

template<typename any, size_t Size>
any &Array<any, Size>::CustomIterator::operator[](std::size_t index)
{
    return this->ite[index];
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator &Array<any, Size>::CustomIterator::operator+=(const difference_type &rhs)
{
    this->ite += rhs;
    return *this;
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator &Array<any, Size>::CustomIterator::operator-=(const difference_type &rhs)
{
    this->ite -= rhs;
    return *this;
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator &Array<any, Size>::CustomIterator::operator++()
{
    ++this->ite;
    return *this;
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator Array<any, Size>::CustomIterator::operator++(int)
{
    CustomIterator temp {this->ite};
    ++(*this);  //equavalent of ++this->ite; //calls overloaded preincrement operator
    return temp;
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator &Array<any, Size>::CustomIterator::operator--()
{
    --this->ite;
    return *this;
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator Array<any, Size>::CustomIterator::operator--(int rhs)
{
    CustomIterator temp {this->ite};
    --(*this);  //equavalent of ++this->ite; //calls overloaded preincrement operator
    return temp;
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator Array<any, Size>::CustomIterator::operator+(const difference_type &rhs) const
{
    return CustomIterator {this->ite + rhs};
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator Array<any, Size>::CustomIterator::operator-(const difference_type &rhs) const
{
    return CustomIterator {this->ite - rhs};
}

template<typename any, size_t Size>
Array<any, Size>::CustomIterator::difference_type Array<any, Size>::CustomIterator::operator-(const CustomIterator &rhs) const
{
    return this->ite - rhs.ite;
}

#endif