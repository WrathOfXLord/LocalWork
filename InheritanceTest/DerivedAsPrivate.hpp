#pragma once

#include "Base.hpp"

class DerivedAsPrivate : private Base {
private:
    string newAsPrivate;
protected:

public:
    DerivedAsPrivate() : newAsPrivate {"newAsPrivate"} {}
    string getNewAsPrivate() const { return newAsPrivate; }
    string getPrivateAsPrivate() const { return getPrivateAsPublic(); }
    string getProtectedAsPrivate() const { return  getProtectedAsPublic(); }
    string getPublicAsPrivate() const { return getPublicAsPublic(); }
};