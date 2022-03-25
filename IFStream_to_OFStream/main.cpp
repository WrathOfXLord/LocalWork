#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::string filename {};
    std::cout << "Enter File Name : ";
    std::getline(std::cin, filename, '.');
    
    std::ifstream readFrom {filename + ".txt", std::ios::in};
    std::string output {filename + "_out.txt"};
    std::ofstream readInto {output, std::ios::out | std::ios::ate};

    std::string read {};
    while(std::getline(readFrom, read))
    {
        readInto << read << std::endl;
    }
    readFrom.close();
    readInto.close();

    return 0;
}