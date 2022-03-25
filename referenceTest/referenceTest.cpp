#include <iostream>

using namespace std;

void incrementNumber(int &num);

void refTest(int &refGiven);

int main()
{
    int number {250};
    cout << "number before incrementing is : " << number << endl;
    incrementNumber(number);
    cout << "number after ibcrementing is : " << number << endl;
    int &ref{number};   // initializing reference, references are aliases to variables,
                        // think of them as constant pointers to variables that cannot be assigned to another variables.
    refTest(ref);
    refTest(number);
    cout << "actual value of number is : " << number << endl;

    return 0;
}

void refTest(int &refGiven)
{
    cout << "incremented given reference value is : " << ++refGiven << endl;
}

void incrementNumber(int &num)
{
    ++num;
}