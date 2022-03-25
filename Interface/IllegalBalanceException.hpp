#pragma once
#include <iostream>


class IllegalBalanceException: public std::exception {
public:
    IllegalBalanceException() noexcept = default;
    virtual ~IllegalBalanceException() = default;   //destructors noexcept as default
    virtual const char *what() const noexcept override {
        return "IllegalBalanceException";
    }
};