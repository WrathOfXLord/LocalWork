#include "Account.hpp"


Account::Account(std::string name, double balance)
: name {name}, balance {balance}
{
    
}

Account::~Account()
{

}

std::ostream &operator<<(std::ostream &outStream, const Account &source)
{
    outStream << "Account : " << source.name << " - " << source.balance << " $" << std::endl;
    return outStream;
}

bool Account::deposit(double amount)
{
    if(amount > 0)
    {
        std::cout << "Account deposit called with " << amount << std::endl;
        balance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(double amount)
{
    if(amount > 0 && balance - amount > 0)
    {
        std::cout << "Account withdraw called with " << amount << std::endl;
        balance -= amount;
        return true;
    }
    return false;
}