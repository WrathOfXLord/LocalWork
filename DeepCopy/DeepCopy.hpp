#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Deep {

private:
    size_t size;
    int *data;

public:
    //constructors
    Deep(size_t size, int initialVal);
    Deep(const Deep &Source);
    //destructor
    ~Deep();

    //getter and setter

    int *getData();
    void setData(int val);

    size_t getSize();
    
};

void printWithCopy(Deep source);
void printWithReference(Deep &source);