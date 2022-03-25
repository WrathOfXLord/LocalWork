#include "DeepCopy.hpp"


int main()
{
    Deep deep1(3, 2);
    Deep deep2(deep1);

    cout << "sizeof deep2 is : " << deep2.getSize() << endl;

    printWithCopy(deep1);
    printWithReference(deep2);

    return 0;
}