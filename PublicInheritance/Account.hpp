#pragma once
#include <string>
#include <iostream>

class Account {
    friend std::ostream &operator<<(std::ostream &outSream, const Account &source);

public:
    std::string name;
    double balance;
    Account(std::string name = "empty", double balance = 0);
    ~Account();
    
    
    bool deposit(double amount);
    bool withdraw(double amount);
};

