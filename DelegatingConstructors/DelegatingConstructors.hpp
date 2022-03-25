#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Player {

private:
    string name;
    unsigned int health;
    unsigned int age;
    size_t xp;

public:
    //implicitly inline methods, because we are defining them inside class declaration
    //inline methods are small optimized methods
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    
    //constructor prototypes
    Player();
    Player(string name);
    Player(string name, unsigned int health, size_t xp);
    Player(string name, unsigned int health, unsigned int age, size_t xp);  

    //destructor
    ~Player(); 

    //method prototypes
    void talk(string any);
    bool isDead();

};
