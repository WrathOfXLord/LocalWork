#pragma once

#include "Base.hpp"

class DerivedAsPrivate : private Base {
private:
    string newAsPrivate;
protected:

public:
    DerivedAsPrivate() : newAsPrivate {"newAsPrivate"} {}
    const string &getNewAsPrivate() const { return newAsPrivate; }
    const string &getPrivateAsPrivate() const { return getPrivateAsPublic(); }
    const string &getProtectedAsPrivate() const { return  getProtectedAsPublic(); }
    const string &getPublicAsPrivate() const { return getPublicAsPublic(); }
};