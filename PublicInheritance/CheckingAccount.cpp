#include "CheckingAccount.hpp"

CheckingAccount::CheckingAccount(std::string name, double balance)
: Account {name, balance}
{

}

CheckingAccount::~CheckingAccount()
{

}

std::ostream &operator<<(std::ostream &outStream, const CheckingAccount &source)
{
    outStream << "Checking Account : " << source.name << " - " << source.balance << " $" << std::endl;
    return outStream;
}

bool CheckingAccount::deposit(double amount)
{
    return Account::deposit(amount);
}

bool CheckingAccount::withdraw(double amount)
{
    return Account::withdraw(amount + withdrawalFee);
}