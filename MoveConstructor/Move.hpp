#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Move {

private:

    int *data;
    
public:
    Move(int val);  //normal constructor
    Move(const Move &source);   //copy constructor
    Move(Move &&source);        //move constructor

    ~Move();

    int getData();
    void setData(int val);
};

void printData(Move &source);
