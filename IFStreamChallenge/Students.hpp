#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Student.hpp"
#include "ReadFile.hpp"

class Students {
    friend class ReadFile;
    friend std::ostream &operator<<(std::ostream &out, const Students &rhs);
private:
    std::vector<Student> students;
public:
    void display() const;
    double meanScore() const;
};