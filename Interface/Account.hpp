#pragma once
#include "I_EasyPrint.hpp"
#include "InsufficentFundsException.hpp"
#include "IllegalBalanceException.hpp"
#include "NegativeAmountException.hpp"
#include "ExceededWithdrawalAmountException.hpp"
#include <vector>

class Account: public I_EasyPrint {
protected:
    std::string name;
    double balance;

public:
    Account(std::string name = "empty", double balance = 0);
    virtual void printUtilFunc(std::ostream &outStream) const override;
    virtual void withdraw(double amount);
    virtual void deposit(double amount);
    virtual ~Account() {};
};

//utility function
void displayAccVec(const std::vector <Account *> &accList);
