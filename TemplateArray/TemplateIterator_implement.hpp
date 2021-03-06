#pragma once
#include <iostream>

template<typename any> class CustomIterator {
    
private:
    any *ite;
public:
    //explicit CustomIterator() : ite {nullptr} {}
    explicit CustomIterator(any *ptr = nullptr) : ite {ptr} {}
    ~CustomIterator() = default;
    bool operator<(const CustomIterator & rhs) const;
    bool operator<=(const CustomIterator & rhs) const;
    bool operator>(const CustomIterator & rhs) const;
    bool operator>=(const CustomIterator & rhs) const;
    bool operator==(const CustomIterator &rhs) const;
    bool operator!=(const CustomIterator &rhs) const;
    any &operator*() const;    //we need to return any reference if we want to use it in foreach loop
    //because if we only return any then it returns only rvalue which cannot be used 
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

template<typename any>
bool CustomIterator<any>::operator<(const CustomIterator &rhs) const
{
    return *(*this) < *rhs;
}

template<typename any>
bool CustomIterator<any>::operator<=(const CustomIterator &rhs) const
{
    return *(*this) <= *rhs;
}

template<typename any>
bool CustomIterator<any>::operator>(const CustomIterator &rhs) const
{
    return *(*this) > *rhs;
}

template<typename any>
bool CustomIterator<any>::operator>=(const CustomIterator &rhs) const
{
    return *(*this) >= *rhs;
}

template<typename any>
bool CustomIterator<any>::operator==(const CustomIterator &rhs) const
{
    //*this , dereferences the current object 
    //but *(*this) firstly dereferences the current object then with overloaded * operator, dereferences this->ite
    return *(*this) == *rhs;
}

template<typename any>
bool CustomIterator<any>::operator!=(const CustomIterator &rhs) const
{
    return !(*(*this) == *rhs);
}

template<typename any>
any &CustomIterator<any>::operator*() const
{
    return *(this->ite);
}

template<typename any>
CustomIterator<any> &CustomIterator<any>::operator++()
{
    ++this->ite;
    return *this;
}

template<typename any>
CustomIterator<any> CustomIterator<any>::operator++(int)
{
    CustomIterator temp {this->ite};
    ++(*this);  //equavalent of ++this->ite; //calls overloaded preincrement operator
    return temp;
}

template<typename any>
CustomIterator<any> &CustomIterator<any>::operator--()
{
    --this->ite;
    return *this;
}

template<typename any>
CustomIterator<any> CustomIterator<any>::operator--(int rhs)
{
    CustomIterator temp {this->ite};
    --(*this);  //equavalent of ++this->ite; //calls overloaded preincrement operator
    return temp;
}

template<typename any>
CustomIterator<any> CustomIterator<any>::operator+(size_t rhs)
{
    return CustomIterator {this->ite + rhs};
}

template<typename any>
CustomIterator<any> CustomIterator<any>::operator-(size_t rhs)
{
    return CustomIterator {this->ite - rhs};
}