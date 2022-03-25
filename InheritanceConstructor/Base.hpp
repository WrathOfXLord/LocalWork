#pragma once

#include <iostream>
using std::cout;
using std::endl;

class Base {
private:
    int value;

protected:
    int multipliedBy2;

public:
    Base() : value {0}, multipliedBy2 {0}  { cout << "Base no args constructor" << endl; }
    Base(int value) : value {value}, multipliedBy2 {value * 2}  { cout << "Base one arg constructor" << endl; }
    Base(const Base &source);
    Base &operator=(const Base &rhs);
    ~Base() { cout << "Base destructor" << endl; }
    void printValues() const;

};