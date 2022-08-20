#include <iostream>
#include <cstring>
#include "Child.hpp"

int main()
{
    Child firstChild {};
    std::cout << "first child's age: " << firstChild.getAge() << "\n";
    firstChild.setFirstName("ali");
    std::cout << "first child's name is now: " << firstChild.getFirstName() << "\n";

    return EXIT_SUCCESS;
}

