#include "Money.hpp"
#include <cstring>

Money::Money(const double cash, const char *currency)
: cash {cash}, cashCurrency {new char [lenCurrency + 1]} 
{
    std::strncpy(this->cashCurrency, currency, this->lenCurrency);
    cashCurrency[lenCurrency] = '\0';
    for(size_t i {0}; i < lenCurrency; ++i)
        cashCurrency[i] = std::toupper(cashCurrency[i]);
    
    int currencyType {currencyCmp(this->cashCurrency)};
    if(!(currencyType == 0 || currencyType == 1 || currencyType == 2))
    {
        cout << "Wrong Currency Type. Currency Based On TRY." << endl;
        std::strncpy(cashCurrency, "TRY", this->lenCurrency);
        cashCurrency[lenCurrency] = '\0';
    }
}

Money::Money(const Money &source)
: Money {source.cash, source.cashCurrency}
{

}

Money::Money(Money &&source)
: cash {source.cash}, cashCurrency{source.cashCurrency}
{
    source.cashCurrency = nullptr;
}

Money Money::operator+(const Money &source)
{
    if(currencyCmp(*this, source) == true)
    {
        Money temp {this->cash + source.cash, this->cashCurrency};
        return temp;
    }

    cout << "Cannot add different currency type cash. " << endl;
    return *this;
}

Money Money::operator-(const Money &source)
{
    if(currencyCmp(*this, source) == true)
    {
        Money temp {this->cash - source.cash, this->cashCurrency};
        return temp;
    }

    cout << "Cannot substract different currency type cashes. " << endl;
    return *this;
}

bool Money::operator==(const Money &source)
{
    if(currencyCmp(*this, source) == true && this->cash == source.cash)
        return true;

    return false;
}

bool Money::operator<(const Money &source)
{
    if(currencyCmp(*this, source) == true && this->cash < source.cash)
        return true;
    else
    {
        Money temp {*this};     //we dont want to change the currency implicitly
        temp.currencyConverter(source.cashCurrency);
        if(temp.cash < source.cash)
            return true;  
    }
    return false;
}

bool Money::operator>(const Money &source)
{
    if(currencyCmp(*this, source) == true && this->cash > source.cash)
        return true;
    else
    {
        Money temp {*this};     //we dont want to change the currency implicitly
        temp.currencyConverter(source.cashCurrency);
        if(temp.cash > source.cash)
            return true;  
    }
    return false;
}

Money &Money::operator=(const Money &source)
{
    if(this == &source) //source reference is not an address so we get the address with the ampersand(&)
        return *this;

    strncpy(this->cashCurrency, source.cashCurrency, this->lenCurrency);
    this->cash = source.cash;
    return *this;
}

Money &Money::operator=(Money &&source)
{
    if(this == &source) //source reference is not an address so we get the address with the ampersand(&)
        return *this;

    this->cashCurrency = source.cashCurrency;
    this->cash = source.cash;
    source.cashCurrency = nullptr;
    return *this;
}

Money::~Money()
{
    delete [] cashCurrency;
}

int currencyCmp(const char *source)
{
    size_t len {std::strlen(source)};
    if(!std::strncmp(source, "TRY", len))
        return 0;   //TRY
    else if(!std::strncmp(source, "EUR", len))
        return 1;   //EUR
    else if(!std::strncmp(source, "USD", len))
        return 2;   //USD

    return -1;      //Wrong Currency  
}

bool currencyCmp(const Money &lhs, const Money &rhs)
{
    if(!std::strncmp(lhs.cashCurrency, rhs.cashCurrency, lhs.lenCurrency))
        return true;   //equals

    return false;      //Wrong Currency or not equals
}

void Money::currencyConverter(const char *currency)
{
    int typeObj {currencyCmp(this->cashCurrency)};
    int typeWanted {currencyCmp(currency)};
    if(typeObj != typeWanted)
    {
        if(typeWanted == 0)        //TRY
        {
            strncpy(this->cashCurrency, currency, this->lenCurrency);
            if(typeObj == 1)    
                cash *= EUR;
            else if(typeObj == 2)
                cash *= USD;

        }
        else if(typeWanted == 1)    //EUR
        {
            strncpy(this->cashCurrency, currency, this->lenCurrency);
            if(typeObj == 0)
                cash /= EUR;
            else if(typeObj == 2)
                cash *= USD / EUR;
        }
        else if(typeWanted == 2)    //USD
        {
            strncpy(this->cashCurrency, currency, this->lenCurrency);
            if(typeObj == 0)
                cash /= USD;
            else if(typeObj == 1)
                cash *= EUR / USD;
        }
    }
    return;
}