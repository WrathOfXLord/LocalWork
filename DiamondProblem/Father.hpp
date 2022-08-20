#ifndef _FATHER_HPP_
#define _FATHER_HPP_

#include "Person.hpp"

class Father: virtual public Person {
public:
    Father() : Person {} {
        
        std::cout << "constructor of derived class: Father\n";
    }

};

#endif