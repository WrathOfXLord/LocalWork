#include "Shape.hpp"
#include <iostream>

void Line::draw(double size)
{
    this->size = size;
    std::cout << "Drawing Open Shape - Line" << std::endl;
}

void Square::draw(double size)
{
    this->size = size;
    std::cout << "Drawing Close Shape - Square" << std::endl;
}