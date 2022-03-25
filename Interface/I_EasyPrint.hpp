#pragma once
#include <iostream>
#include <string>


//the class down below is an interface class
//interfaces are a type of abstract class that only have pure virtual functions and virtual destructor
//operator is a friend method not a member function
//Interface classes are alike abstract classes.
class I_EasyPrint {
    friend std::ostream &operator<<(std::ostream &outStream, const I_EasyPrint &rhs);
public:
    virtual void printUtilFunc(std::ostream &outStream) const = 0;
    virtual ~I_EasyPrint() = default; //this one equal to "virtual ~I_EasyPrint() { }"
};


