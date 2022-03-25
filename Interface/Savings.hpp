#pragma once
#include "Account.hpp"
#include "NegativeIntRateException.hpp"

class Savings final: public Account {
protected:
    double interestRate;
public:
    Savings(std::string name = "empty", double balance = 0, double intR = 0);
    virtual void printUtilFunc(std::ostream &outStream) const override final;
    virtual void withdraw(double amount) override final;
    virtual void deposit(double amount) override final;
    virtual double getIntRate() const { return interestRate; }
    virtual ~Savings() {};
};