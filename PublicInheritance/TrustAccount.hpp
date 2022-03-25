#pragma once
#include "SavingsAccount.hpp"

class TrustAccount : public SavingsAccount {
    friend std::ostream &operator<<(std::ostream &outSream, const TrustAccount &source);
private:
    size_t countWithdrawals;
public:
    TrustAccount(std::string name = "empty", double balance = 0, double intRate = 0);
    ~TrustAccount();    
    
    bool deposit(double amount);
    bool withdraw(double amount);
};