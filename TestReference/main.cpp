#include <iostream>
#include "TestReference.hpp"

using TR = TestReference;

int main()
{
    TR t1 {};
    std::cout << t1.getVal() << "\n";
    t1.getValueRef() = 34;
    std::cout << t1.getVal() << "\n";

    return 0;
}