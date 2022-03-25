#include "I_EasyPrint.hpp"

std::ostream &operator<<(std::ostream & outStream, const I_EasyPrint &rhs)
{
    rhs.printUtilFunc(outStream);
    return outStream;
}