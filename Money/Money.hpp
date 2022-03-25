#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Money {

private:
    double cash;
    const size_t lenCurrency {3};
    char *cashCurrency;
    const double TRY {1};
    const double USD {7};
    const double EUR {9};
    
public:
    Money(const double cash = 0, const char *currency = "TRY");
    Money(const Money &source);
    Money(Money &&source);

    Money operator+(const Money &source);
    Money operator-(const Money &source);
    bool operator==(const Money &source);
    bool operator<(const Money &source);
    bool operator>(const Money &source);
    Money &operator=(const Money &source);
    Money &operator=(Money &&source);

    ~Money();

    void display() const;
    void currencyConverter(const char *currency);
    void setMoney(const Money &source);
    void setMoney(const double &source);

    double getMoney() const { return this->cash; }

    friend bool currencyCmp(const Money &lhs, const Money &rhs);

};

int currencyCmp(const char *source);