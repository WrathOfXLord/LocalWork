#include "SavingsAccount.hpp"
#include <iostream>

SavingsAccount::SavingsAccount(std::string name, double balance, double intRate)
: Account {name, balance}, interestRate {intRate}
{

}

SavingsAccount::~SavingsAccount()
{

}

std::ostream &operator<<(std::ostream &outStream, const SavingsAccount &source)
{
    outStream << "Savings Account : " << source.name << " - " << source.balance << " $" << " - "
                                      << source.interestRate << " interest rate." << std::endl;
    return outStream;
}

bool SavingsAccount::deposit(double amount)
{
    std::cout << "Savings Account deposit called with " << amount << std::endl;
    amount += amount * interestRate / 100;
    return Account::deposit(amount);

}

bool SavingsAccount::withdraw(double amount)
{

    std::cout << "Savings Account withdraw called with " << amount << std::endl;
    return Account::withdraw(amount);

}