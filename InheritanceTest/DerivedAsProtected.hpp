#pragma once

#include "Base.hpp"

class DerivedAsProtected : protected Base {
private:
    string newAsProtected;
protected:

public:
    DerivedAsProtected() : newAsProtected {"newAsProtected"} {}

    const string &getNewAsProtected() const { return newAsProtected; }

    const string &getPrivateAsProtected() const { return getPrivateAsPublic(); }   //private data members are still private and cannot be accesses from derived class
                                                                            //so we need to use base class' getter function to return it's value
    const string &getProtectedAsProtected() const { return  protectedFromOutside; }   //protected ones are still protected
    const string &getPublicAsProtected() const { return freeForAll; } //public base members are now protected because we inherited as protected

};