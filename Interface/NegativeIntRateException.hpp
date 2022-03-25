#pragma once
#include <iostream>

class NegativeIntRateException: public std::exception {
public:
    NegativeIntRateException() noexcept = default;
    virtual ~NegativeIntRateException() = default;
    virtual const char *what() const noexcept override { return "Negative Int Rate Exception"; }
};