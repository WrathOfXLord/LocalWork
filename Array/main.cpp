#include "Array.hpp"


int main()
{
    const int x = 5;
    my::Array<int, 5> myArr {5, 4, x, 6, 7};
    std::cout << "myArr is : " << myArr << '\n';
    // std::cout << myArr.length() << '\n';
    return 0;
}