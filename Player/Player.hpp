//guards to prevent use the hpp file multiple times
#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
//or simply we could have used pragma but some compilers doesn't know what "#pragma once" is.
// #pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Player {
private:
    string name;
    size_t xp;
    static size_t playerCount;
    unsigned int health;
    unsigned int age;
public:
    //implicitly inline methods, because we are defining them inside class declaration
    //inline methods are small optimized methods
    const string &getName() const { return name; }
    void setName(string name) { this->name = name; }

    int getXp() const { return xp; }
    void setXp(size_t xp) { this->xp = xp; }

    static size_t getPlayerCount();
    
    //constructor prototypes
    Player();
    Player(string name);
    Player(const Player &source_to_copy); //copy constructor  

    //destructor
    ~Player(); 

    //method prototypes
    void talk(string any);
    bool isDead();

};

void printPlayer(const Player &p);

#endif