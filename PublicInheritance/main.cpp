#include "SavingsAccount.hpp"
#include <iostream>

using namespace std;

int main()
{
    Account a1;
    a1.deposit(5000);
    a1.withdraw(250);
    cout << "========================================" << endl;
    SavingsAccount sa1;
    sa1.deposit(2000);
    sa1.withdraw(100);

    return 0;
}