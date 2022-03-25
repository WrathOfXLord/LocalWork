#include <iostream>
#include <string>


int main()
{
    std::cout << "(2 == 2) is : " << ((2 == 2)? "true\n" : "false\n"); // << has higher precedence than ? so we need parantheses
    return 0;
}

