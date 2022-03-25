#pragma once
#include <iostream>

class NegativeAmountException: public std::exception {
public:
    NegativeAmountException () noexcept = default;
    virtual ~NegativeAmountException() = default;
    virtual const char *what() const noexcept override { return "Negative Amount Exception"; }
};