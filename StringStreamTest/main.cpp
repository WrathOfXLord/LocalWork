#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <string>


int main()
{
    std::string name1 {"Ali Firat"};
    std::istringstream readString {"hey there"};

    std::string temp1;
    std::string temp2;
    readString >> temp1 >> temp2;
    
    std::cout << "temp1 is : " << temp1 << std::endl;
    std::cout << "temp2 is : " << temp2 << std::endl;

    readString.clear();
    readString = std::move(std::istringstream {name1});
    readString >> temp1 >> temp2;

    std::cout << "temp1 is : " << temp1 << std::endl;
    std::cout << "temp2 is : " << temp2 << std::endl;

    std::ostringstream writeString;
    writeString << std::setw(5) << std::left << temp1
                << std::setw(5) << temp2 << std::endl;

    std::cout << "writeString buffer contains : " << writeString.str();

    std::stringstream readWriteString {name1};
    std::cout << "readWriteString buffer contains : " << readWriteString.str() << std::endl;
    //doing this will clear initialized value of stringstream object
    
    readWriteString << std::setw(10) << std::left << temp1
                    << std::setw(10) << temp2 << std::endl;

    std::cout << "readWriteString buffer contains : " << readWriteString.str();

    readWriteString >> temp1 >> temp2;
    std::cout << temp1 << "." << std::endl;
    std::cout << temp2 << "." << std::endl;
    //asks user to enter a number to read into double variable
    bool done = false;
    std::string userInput {};
    double value {};
    std::string test {};
    do {
        std::cout << "\n\nPlease enter a double value to store in value: ";
        std::cin >> userInput;
        std::istringstream store {userInput};
        if(store >> value >> test) {
            std::cout << "value succesfully stored in value" << std::endl;
            done = true;
            std::cout << "value is = " << value << std::endl;
            std::cout << "test is = " << test << std::endl;
        } else {
            std::cout << "invalid value, please try again" << std::endl;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores all characters which comes after "value" until newline character inside of cin buffer

    } while(!done);


    return 0;
}