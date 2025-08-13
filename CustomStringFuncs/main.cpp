#include <iostream>
#include <string>
#include <cstring>

std::string capitalise(std::string str) {
    if(str.size() == 0) {
        return str;
    }
    str[0] = std::toupper(str[0]);
    size_t index {};
    do {
        index = str.find(" ", index);

        if(index == std::string::npos) {
            break;
        }
        ++index;
        str[index] = std::toupper(str[index]);
        
    } while(1);

    return str;
}

std::string &trim(std::string &str) {
    for(size_t index {}, mid {str.size() / 2}; index < mid; ++index) {
        if(str[index] != ' ') {
            str.erase(0, index);
            break;
        }
    }

    for(size_t index {str.size() - 1}, mid {str.size() / 2}, end {str.size() - 1}; index >= mid; --index) {
        if(str[index] != ' ') {
            str.erase(index + 1, end);
            break;
        }
    }
    return str;
}


int main()
{
    std::string test {"      ali firat      "};
    std::cout << "before test: -" << test << "-\n";
    std::cout << " after test: -" << trim(test) << "-\n";
    return EXIT_SUCCESS;
}