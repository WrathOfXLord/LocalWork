#ifndef _CHILD_HPP
#define _CHILD_HPP

#include "Father.hpp"
#include "Mother.hpp"

class Child: public Father, public Mother {
public:
    Child() : Father {}, Mother {} {
        std::cout << "constructor of derived of derived: Child\n";
    }
};

#endif