#include "Base.hpp"

Base::Base(const Base &source)
: value {source.value}, multipliedBy2 {source.multipliedBy2}
{
    cout << "Base copy constructor" << endl;
}

Base &Base::operator=(const Base &rhs)
{
    if(this == &rhs)
        return *this;

    this->value = rhs.value;
    this->multipliedBy2 = rhs.multipliedBy2;
    cout << "Base overloaded operator assignment" << endl;
    return *this;
}

void Base::printValues() const
{
    cout << "Value is = " << value << endl;
    cout << "Multiplied By 2 is = " << multipliedBy2 << endl;
}