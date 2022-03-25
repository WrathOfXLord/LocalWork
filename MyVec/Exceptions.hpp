#pragma once
#include <iostream>

class EmptyVectorException: public std::exception {
public:
    EmptyVectorException() noexcept = default;
    virtual ~EmptyVectorException() = default;
    virtual const char *what() const noexcept override { return "Empty Vector Exception"; }
};

class RankOutOfBoundsException: public std::exception {
public:
    RankOutOfBoundsException() noexcept = default;
    virtual ~RankOutOfBoundsException() = default;
    virtual const char *what() const noexcept override { return "Given Rank is Out Of Bounds Exception"; }
};

class VectorIndexOutOfRangeException: public std::exception {
public:
    VectorIndexOutOfRangeException() noexcept = default;
    virtual ~VectorIndexOutOfRangeException() = default;
    virtual const char *what() const noexcept override { return "Vector Index Out Of Range Exception"; }
};