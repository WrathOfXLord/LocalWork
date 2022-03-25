#pragma once

#include "Base.hpp"

class DerivedAsProtected : protected Base {
private:
    string newAsProtected;
protected:

public:
    DerivedAsProtected() : newAsProtected {"newAsProtected"} {}

    string getNewAsProtected() const { return newAsProtected; }

    string getPrivateAsProtected() const { return getPrivateAsPublic(); }   //private data members are still private and cannot be accesses from derived class
                                                                            //so we need to use base class' getter function to return it's value
    string getProtectedAsProtected() const { return  protectedFromOutside; }   //protected ones are still protected
    string getPublicAsProtected() const { return freeForAll; } //public base members are now protected because we inherited as protected

};