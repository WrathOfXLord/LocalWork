#include "TrustAccount.hpp"

TrustAccount::TrustAccount(std::string name, double balance, double intRate)
: SavingsAccount {name, balance, intRate}, countWithdrawals {0}
{

}

TrustAccount::~TrustAccount()
{

}

std::ostream &operator<<(std::ostream &outStream, const TrustAccount &source)
{
    outStream << "Trust Account : " << source.name << " - " << source.balance << " $" << " - "
                              << source.getInterestRate() << " interest rate." << std::endl;
    return outStream;
}

bool TrustAccount::deposit(double amount)
{
    std::cout << "Trust Account deposit called with " << amount << std::endl;
    double bonus {(amount >= 5000.0)? 50.0 : 0.0};
    amount += amount * this->getInterestRate() / 100 + bonus;
    return Account::deposit(amount);

}

bool TrustAccount::withdraw(double amount)
{
    ++countWithdrawals;
    if(countWithdrawals >= 4)
        return false;
    std::cout << "Savings Account withdraw called with " << amount << std::endl;
    return Account::withdraw(amount);

}