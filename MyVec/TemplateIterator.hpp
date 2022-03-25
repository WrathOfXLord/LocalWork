#pragma once
#include <iostream>


template<typename type> class CustomIterator {
private:
    type *ite;
public:
    //explicit CustomIterator() : ite {nullptr} {}
    explicit CustomIterator(type *ptr = nullptr) : ite {ptr} {}
    ~CustomIterator() = default;
    bool operator==(const CustomIterator &rhs) const;
    bool operator!=(const CustomIterator &rhs) const;
    type &operator*() const;    //we need to return type reference if we want to use it in foreach loop
    //because if we only return type then it returns only rvalue which cannot be used 
    //referenced for loop something like this: for(auto &x:container)
    //initial value of reference to non-const must be an lvalue but container in the foreach loop returns rvalue without the reference
    //when it dereferenced by foreach loop
    CustomIterator &operator++();
    CustomIterator operator++(int);
    CustomIterator &operator--();
    CustomIterator operator--(int);
    CustomIterator operator+(size_t rhs);
    CustomIterator operator-(size_t rhs);
};

template<typename type>
bool CustomIterator<type>::operator==(const CustomIterator &rhs) const
{
    //*this , dereferences the current object 
    //but *(*this) firstly dereferences the current object then with overloaded * operator, dereferences this->ite
    return this->ite == rhs.ite;
}

template<typename type>
bool CustomIterator<type>::operator!=(const CustomIterator &rhs) const
{
    return !(this->ite == rhs.ite);
}

template<typename type>
type &CustomIterator<type>::operator*() const
{
    return *(this->ite);
}

template<typename type>
CustomIterator<type> &CustomIterator<type>::operator++()
{
    ++this->ite;
    return *this;
}

template<typename type>
CustomIterator<type> CustomIterator<type>::operator++(int)
{
    CustomIterator temp {this->ite};
    ++(*this);  //equavalent of ++this->ite; //calls overloaded preincrement operator
    return temp;
}

template<typename type>
CustomIterator<type> &CustomIterator<type>::operator--()
{
    --this->ite;
    return *this;
}

template<typename type>
CustomIterator<type> CustomIterator<type>::operator--(int rhs)
{
    CustomIterator temp {this->ite};
    --(*this);  //equavalent of ++this->ite; //calls overloaded preincrement operator
    return temp;
}

template<typename type>
CustomIterator<type> CustomIterator<type>::operator+(size_t rhs)
{
    return CustomIterator {this->ite + rhs};
}

template<typename type>
CustomIterator<type> CustomIterator<type>::operator-(size_t rhs)
{
    return CustomIterator {this->ite - rhs};
}