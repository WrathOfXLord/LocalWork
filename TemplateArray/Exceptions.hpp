#pragma once
#include <iostream>

class OutOfBoundsException: public std::exception {
public:
    OutOfBoundsException() noexcept = default;
    ~OutOfBoundsException() = default;
    virtual const char *what() const noexcept override { return {"Out Of Bounds Exception"}; }
};

