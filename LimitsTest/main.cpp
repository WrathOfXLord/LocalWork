#include <iostream>
#include <limits>


int main()
{
    //values shown below are machine dependant
    std::cout << "INTEGERS\n";
    std::cout << "limits for the max unsigned long long (2^64 bits minimum) : " << std::numeric_limits<unsigned long long>::max() << '\n';
    std::cout << "limits for the max signed long long (2^63 bits minimum - 1 goes for sign bit) : " << std::numeric_limits<long long>::max() << '\n';
    std::cout << "limits for the max unsigned long (2^32 bits minimum) : " << std::numeric_limits<unsigned long>::max() << '\n';
    std::cout << "limits for the max signed long (2^31 bits minimum - 1 goes for sign bit) : " << std::numeric_limits<long>::max() << '\n';
    std::cout << "limits for the max unsigned int (2^16 or 2^32 bits, varies by machine) : " << std::numeric_limits<unsigned int>::max() << '\n';
    std::cout << "limits for the max signed int (2^15 or 2^31 bits, varies by machine - 1 bit goes for sign) : " << std::numeric_limits<int>::max() << '\n';
    std::cout << "limits for the max unsigned short (2^16 bits) : " << std::numeric_limits<unsigned short>::max() << '\n';
    std::cout << "limits for the max signed short (2^15 bits - 1 goes for sign) : " << std::numeric_limits<short>::max() << '\n';
    std::cout << "limits for the max unsigned char (2^8 bits) : " << UCHAR_MAX << '\n';
    std::cout << "limits for the max signed char (2^7 bits - 1 goes for sign) : " << CHAR_MAX << '\n';
    std::cout << "======================================================================================================================================\n";
    std::cout << "FRACTIONAL NUMBERS\n";
    std::cout << "limits for the max long double : " << std::uppercase << std::numeric_limits<long double>::max() << '\n';
    std::cout << "limits for the min long double : " << std::numeric_limits<long double>::min() << '\n';
    std::cout << "limits for the max double : " << std::numeric_limits<double>::max() << '\n';
    std::cout << "limits for the min double : " << std::numeric_limits<double>::min() << '\n';
    std::cout << "limits for the max float : " << std::numeric_limits<float>::max() << '\n';
    std::cout << "limits for the min float : " << std::numeric_limits<float>::min() << '\n';
    return 0;
}