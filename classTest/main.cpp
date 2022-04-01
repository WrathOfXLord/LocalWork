#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
public:
    Player(string any);
    
    //getter and setters
    const string &getName() const;
    void setName(string any);   // bool OK too

private:    
    string name;
    int health;
    int xp;

// methods
    void talk(string any);
    bool isDead();
};

int main()
{
    Player ali("ali");
    
    Player hero("batman");
    cout << "name of second player is : " << hero.getName() << endl;

    cout << "Please enter the name you want to be replaced with the old one : ";
    string NewName;
    cin >> NewName;
    std::string ref {hero.getName()};
    hero.setName(NewName);
    cout << "New name is now : " << hero.getName() << endl;
    return 0;
}

Player::Player(string any)
: name {any}, health {100}, xp {0}
{

}

const string &Player::getName() const
{
    return name;
}

void Player::setName(string any)
{
    name = any;
}