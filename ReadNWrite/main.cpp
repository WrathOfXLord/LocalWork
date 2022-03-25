#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <bitset>
#include <sstream>
#include <codecvt>
#include <locale>



int main()
{
    setlocale(LC_ALL, "Turkish");
    std::string text;
    std::string readOut;
    std::string path {"C:\\Users\\alifi\\Downloads"};
    for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(path))
    {
        std::bitset<32> txt;
        std::fstream ifs {entry.path()};
        while(std::getline(ifs, readOut));
        std::cout << '\n' << entry.path() << " 1 \n";
        std::cout << readOut << " 2 \n";
        ifs.close();
        std::stringstream ss {readOut};
        while(ss >> txt)
            text += txt.to_ulong();
    } 
    
    // std::fstream writeIntoFile {"message.txt", std::ios::out};
    // if(writeIntoFile << text)
    //     std::cout << "writing into file is succesfully done\n";
    // writeIntoFile.close();
    
    return 0;
}