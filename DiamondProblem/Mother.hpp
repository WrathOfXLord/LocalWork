#ifndef _MOTHER_HPP_
#define _MOTHER_HPP_

#include "Person.hpp"

class Mother: virtual public Person {
public:
    Mother() : Person {} {
        std::cout << "constructor of derived class: Mother\n";
    }
};

#endif