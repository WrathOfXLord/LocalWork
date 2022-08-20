#include <iostream>

template <typename T>
concept ConvertibleToString = std::convertible_to<T, std::string>;


void printStr(ConvertibleToString auto &c) {
    std::string val {c};
    std::cout << val << "\n";
}

template<typename T>
    requires std::convertible_to<T, double>
    auto addAndReturn(const T &value) {
        T tmp {value};
        tmp += value;
        return tmp;
    }

int main() 
{
    // char letter {'c'};
    // std::string test {letter};
    // std::cout << test << "\n";

    // std::cout << addAndReturn(std::string {"32"}) << "\n";
    std::cout << addAndReturn(32) << "\n";

    // printStr('c');
    return EXIT_SUCCESS;
}