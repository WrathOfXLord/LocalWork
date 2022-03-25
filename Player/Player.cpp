#include "Player.hpp"

//unsigned static data member to hold the player number for the class
//static data members typically initialised in .cpp files as down below
size_t Player::playerCount = 1000000000;


//static data members only works with static methods
//and static member functions must only work with static datas
size_t Player::getPlayerCount() 
{
    return playerCount;
}

//constructor definitions
Player::Player()
:health {100}, age {18}, xp {0}
{
    ++playerCount;
    cout << "No argument constructor is called." << endl;
}

Player::Player(string name)
: health {100}, age {18}, name {name}, xp {0}
{
    ++playerCount;
    cout << "Single argument constructor is called." << endl;
    cout << "New player is created named " << this->name << "." << endl;
}

//sınıf, raw pointer üyeye sahip olduğunda copy constructor yazılmalıdır.
//çünkü pointer'ın kendisi kopyalanır, işaret ettiği değil !
//const parametre çağırmak en doğrusu veriyi değiştirmediğimizden dolayı.
//eğer copy constructor yazılmazsa compiler otomatik olarak bir tane bize verir.
Player::Player(const Player &source_to_copy)
//we could have used delegating constructor instead of initialisation list
: health {source_to_copy.health}, age {source_to_copy.age}, name {source_to_copy.name}, xp {source_to_copy.xp}
{
    cout << "copy constructor initialised the object named : " << name << "." << endl;
}

//destructor definition
Player::~Player()
{
    cout << "Destructor is called for " << this->name << "." << endl;
    cout << "This object no longer exists." << endl;
}


//member functions
void Player::talk(string any)
{
    cout << name << " : " << any << endl;
}

bool Player::isDead()
{
    if(health == 0)
    {
        cout << "player is dead." << endl;
        return true;
    }
    
    cout << "player is alive." << endl;  
    return false;
}

//deep copy - copy of object created by copy constructor in the function
void printPlayer(const Player &p)
{
    cout << "Player name is : " << p.getName() << endl;
    cout << "Player experience is : " << p.getXp() << endl;
}