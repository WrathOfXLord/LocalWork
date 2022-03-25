#pragma once
#include <iostream>


class ExceededWithdrawalAmountException: public std::exception {
public:
    ExceededWithdrawalAmountException() noexcept = default;
    virtual ~ExceededWithdrawalAmountException() = default; //destructors noexcept as default
    virtual const char *what() const noexcept override {
        return "Exceeded Withdrawal Amount Exception";
    }
};