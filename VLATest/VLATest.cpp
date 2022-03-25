#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

int main()
{
    std::string userIn {};
    std::cout << "Enter a valid value : ";
    std::cin >> userIn;
    std::stringstream strStrm;
    strStrm << userIn;
    size_t val {};
    if(strStrm >> val)
        std::cout << "Value stored in a variable - " << val << "\n";
    else  {
        std::cerr << "Failed to store the value\n";
        return -1;
    }
    const size_t len {val};
    int arr[len] {};    //this is not standard c++, mingw has an extension to compile it, this would give a compilation error if we were using different compiler
    for(size_t i {}; i != len; ++i)
        std::cout << std::left << std::setw(4) << arr[i];
    return 0;
}