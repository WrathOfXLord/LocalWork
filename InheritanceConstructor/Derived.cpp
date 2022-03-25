#include "Derived.hpp"

Derived::Derived()
: Base {}, multipliedBy3 {0}, multipliedBy4 {0} //explicitly using base class' no arg constructor to initialise inherited data
{   //Base {} is delegating constructor, the same applies the down below
    cout << "Derived no args constructor" << endl;
}

Derived::Derived(int value)
: Base {value}, multipliedBy3 {value * 3}, multipliedBy4 {value * 4}    //explicitly using base class' one arg constructor to initialise inherited data
{   //if we didn't explicitly use base class constructor then compiler 
    //implicitly would have used base class' default constructor to initialise inherited data which causes wrong initialised inherited data etc.
    cout << "Derived one arg constructor" << endl;
}

Derived::Derived(const Derived &source)
: Base {source}, multipliedBy3 {source.multipliedBy3}, multipliedBy4 {source.multipliedBy4}
{
    cout << "Derived copy constructor" << endl;
}

Derived &Derived::operator=(const Derived &rhs)
{
    if(this == &rhs)
        return *this;

    this->Base::operator=(rhs); //to assign base of rhs to base of lhs, remember Derived is a base. 
                                //and we dont need to provide "this->" since we are already in this object
    this->multipliedBy3 = rhs.multipliedBy3;
    this->multipliedBy4 = rhs.multipliedBy4;

    cout << "Derived overloaded operator assignment" << endl;
    return *this;
}

Derived::~Derived()
{
    cout << "Derived destructor" << endl;
}

void Derived::printValues() const
{
    cout << "Multiplied By 3 is = " << multipliedBy3 << endl;
    cout << "Multiplied By 4 is = " << multipliedBy4 << endl;
}

