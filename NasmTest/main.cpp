#include <iostream>


extern "C" int someReturnableValue();

int main() {

    std::cout << "The result is: " << someReturnableValue() << "\n";

    return 0;
}