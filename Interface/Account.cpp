#include "Account.hpp"
#include <string>

Account::Account(std::string name, double balance) 
: name {name}, balance {balance} 
{
    if(balance < 0)
        throw IllegalBalanceException {};
}

void Account::printUtilFunc(std::ostream &outStream) const
{
    outStream << name << " - " << balance;
}

void Account::withdraw(double amount)
{
    if(amount < 0)
        throw NegativeAmountException {};
    if(balance - amount < 0)
        throw InsufficentFundsException {};
    
    balance -= amount;
    std::cout << "withdrawal from account " << amount << " amount" << std::endl;
}

void Account::deposit(double amount)
{
    if(amount < 0)
        throw NegativeAmountException {};
    balance += amount;
    std::cout << "deposit into account " << amount << " amount" << std::endl;
}

void displayAccVec(const std::vector<Account *> &accList)
{
    for(Account *ptr : accList)
        std::cout << "Account [" << *ptr << "]" << std::endl;;
    std::cout << std::endl;
}