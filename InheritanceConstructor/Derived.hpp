#pragma once

#include "Base.hpp"

class Derived : public Base {
private:
    int multipliedBy3;

protected:
    int multipliedBy4;

public:
    Derived();
    Derived(int value);
    Derived(const Derived &source);
    Derived &operator=(const Derived &rhs);
    ~Derived();

    void printValues() const;
};