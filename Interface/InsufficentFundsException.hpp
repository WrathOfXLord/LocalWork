#pragma once
#include <iostream>



class InsufficentFundsException: public std::exception {
public:
    InsufficentFundsException() noexcept = default;
    virtual ~InsufficentFundsException() = default; //destructors noexcept as default
    virtual const char* what() const noexcept override { 
        return "Insufficent Funds Exception";
    }
};