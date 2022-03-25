#pragma once
#include <iostream>

class FileIsNotOpenedException: public std::exception {
public:
    FileIsNotOpenedException() noexcept = default;
    virtual ~FileIsNotOpenedException() = default;
    virtual const char *what() const noexcept override {
        return " ex.what(): File Could Not Be Opened";
    }
};