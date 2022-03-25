#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//using namespace std;

void input_data(string &input)
{
    cout << "Please enter the string that you want to be saved (24 chars max) : ";
    std::getline(cin, input);   
}

void print(string &input)
{
    cout << "\"" << input << "\"" << " printed." << endl;
}

int main()
{
    string input;
    string  *ptr_to_str {new string [25]};
    for(auto i {0}; i < 4; i++){
        input_data(input);
        ptr_to_str[i] = input;
        print(ptr_to_str[i]);

    }

    delete [] ptr_to_str;
    return 0;
}