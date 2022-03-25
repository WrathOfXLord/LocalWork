#pragma once
#include "Account.hpp"

//derived class of Account
//it is public because Savings Account "is a/an" Account
class SavingsAccount : public Account {
    friend std::ostream &operator<<(std::ostream & outStream, const SavingsAccount &source);
private:
    double interestRate;

protected:
    double getInterestRate() const { return interestRate; }
public:
    
    SavingsAccount(std::string name = "empty", double balance = 0, double intRate = 0);
    ~SavingsAccount();

    bool deposit(double amount);
    bool withdraw(double amount);

};