#include "Player.hpp"

using namespace std;

int main()
{    
    Player p1("batman");
    Player p2 {p1}; //copy of object explicitly created by copy constructor
    p1.setName("vulk");
    printPlayer(p1); //copy constructor will be called to create a copy for function to print
    p1.talk("who am i ?");
    cout << "you are " << "the " << p1.getName() << "." << endl;
    p1.isDead();
    cout << "you are no longer " << p1.getName() << ", ";
    p1.setName("superman");
    cout << "you are now " << p1.getName() << "." << endl;
    cout << endl << endl;
    cout << "Total player count is now : " << Player::getPlayerCount() << endl;

    Player *enemy {new Player {"joker"}};
    cout << "Total player count is now : " << Player::getPlayerCount() << endl;
    delete enemy;

    return 0;
}