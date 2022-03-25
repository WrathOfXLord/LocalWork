#include <iostream>
#include <string>


int main()
{
    std::string a {"hello there"};
    std::cout << "a is : " << a << std::endl;

    std::string b {std::move(a)};


    std::cout << "a is : " << a << std::endl;
    std::cout << "b is : " << b << std::endl;

    return 0;
}