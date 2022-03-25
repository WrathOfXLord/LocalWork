#include "Savings.hpp"
#include <string>

Savings::Savings(std::string name, double balance, double intR) 
: Account {name, balance}, interestRate {intR} 
{
    if(interestRate < 0)
        throw NegativeIntRateException {};
}

void Savings::printUtilFunc(std::ostream &outStream) const
{
    outStream << name << " - " << balance << " - " << interestRate;
}

void Savings::withdraw(double amount)
{
    if(amount > balance / 5)
        throw ExceededWithdrawalAmountException {};

    this->Account::withdraw(amount);
    std::cout << "withdrawal from Savings " << amount << " amount" << std::endl;

}

void Savings::deposit(double amount)
{
    this->Account::deposit(amount);
    double bonus {amount * interestRate / 100};
    balance += bonus;
    std::cout << "deposit into savings " << amount 
              << " amount" << " with " 
              << bonus << " amount bonus." << std::endl;    
}
