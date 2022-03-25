#include <iostream>
#include <locale>
#include <typeinfo>

char toUpper(const char &ch) {
    if(ch >= 'a' and ch <= 'z')
        return ch - 32;
    return ch;
}

int main()
{
    std::setlocale(LC_ALL, "Turkish");
    char x = 'x';
    std::cout << "upper of (x): " << toUpper(x) << "\n";

    std::string testStr {"thiS Is a tEsT"};

    for(char &index:testStr) {
        index = toUpper(index);
    }
    std::cout << testStr << "\n";
    std::cout << "İŞ accent char test\n";
    std::string test = "Ş";
    std::cout << "type: " << typeid(test).name() << " value: " << (int)test[0] << "\n";
    char tt[] = "\uc3a7";
    std::cout << "\ntest: " << tt << "\n";
    return 0;
}