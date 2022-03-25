#include <iostream>
#include <locale>
#include <sstream>
#include <string>

/**
 * vscode türkçe karakterleri göstermiyor konsoldan compile edilmeli
 */

int main()
{
    std::setlocale(LC_ALL, "tr_TR.UTF-16");
    std::cout << "Enter character: ";
    unsigned int c {};
    std::string in {};
    std::cin >> in;
    std::stringstream ss {in};
    if(ss >> c) {
        std::cout << "success\n";
    } else
        std::cout << "fail\n";
    std::cout << "char c: " << c << " (" << static_cast<unsigned int>(c) << ")" << " \n";
    std::cout << "string was: " << in << "\n";


}