#pragma once
#include "Account.hpp"

class CheckingAccount : public Account {
    friend std::ostream &operator<<(std::ostream &outStream, const CheckingAccount &source);
private:
    const double withdrawalFee {1.5};
public:
    CheckingAccount(std::string name = "empty", double balance = 0);
    ~CheckingAccount();    
    
    bool deposit(double amount);
    bool withdraw(double amount);
};