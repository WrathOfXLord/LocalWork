#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // cout << "Enter your input : " ;
    // string newStr;
    // cin >> newStr;
    // cout << "your input is below" << endl;
    // cout << newStr << endl;
    // cout.width(10);
    // cout << newStr << endl;
    // cout.width(10);
    // do not do the following statement:
    // char *ptr {(char *)"hey there"};
    const char *ptr {"hey there"};  //this one OK.
    
    cout << ptr << endl;

    char newArr[] {"heyyo"};

    cout << newArr << endl;
    cout << "size of ptr string is : " << sizeof(newArr)/sizeof(char) << endl;

    return 0;
} 