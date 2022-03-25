#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>


int main()
{
    long long int value {};
    bool done {};
    do {
        std::cout << "Enter the value you want to be stored: ";
        std::string input;
        std::cin >> std::setw(12) >> input; //std::setw(val) only works for 1 input which is pretty good thing. And only works with std::string or char *.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "input : " << input << '\n';
        std::stringstream ss {input};
        if(ss >> value) {
            std::cout << "you succesfully stored the value.\n";
            std::cout << "value is : " << value << '\n';
            done = true;
        } else {
            std::cerr << "you failed to store the value\n";
            // ss.clear();
            // ss.str("");
        }
        

    } while(!done);
    
    return 0;
}