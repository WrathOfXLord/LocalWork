#include <iostream>
#include <sstream>

// These both headers are exist in my repo that named LocalWork
#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"
#include "../BLUEPRINTS/AtoLL/AtoLL.hpp"

// void *operator new(std::size_t size) 
// {
//     std::cout << "Allocating " << size << " bytes of memory from the heap.\n";
//     return std::malloc(size);
// }

// void operator delete(void *memory, std::size_t size)
// {
//     std::cout << "Releasing " << size << " bytes of memory from the heap.\n";
//     std::free(memory);
// }


/**
 * @brief 
 * if user sends bad input, clear std::cin buffer until newline
 * 
 */
void clearConsoleInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// void setVarByInputAndValidate(size_t &var) 
// {
//     std::string buffer;
//     std::cout << "str buffer has been created\n";
//     buffer.reserve(20);
//     std::cout << "reserved 20 chars for buffer\n";

//     for(bool done {}; !done; ) {
//         try
//         {
//             std::cout << "Please enter an integer value: ";
//             std::cin >> std::setw(19) >> buffer;
//             TimeCounter t;
//             var = std::stoull(buffer);
//             t.timedelta();

//             done = true;
//             std::cout << "value : " << var << "\n";
            
//         } catch(const std::exception& e) {
//             clearConsoleInput();
//         }
//     }
// }


// void setVarByInputAndValidateSS(size_t &var)
// {
//     std::string buffer;
//     std::cout << "str buffer has been created\n";
//     buffer.reserve(20);
//     std::cout << "reserved 20 chars for buffer\n";
//     bool done {};
//     do {
//         std::cout << "Please enter an integer value: ";
//         std::cin >> std::setw(19) >> buffer;

//         TimeCounter t;
//         std::stringstream ss {buffer};
//         if(ss >> var) {
//             t.timedelta();
//             done = true;
//             std::cout << "value: " << var << "\n";
//         }
//         clearConsoleInput();
//     } while(!done);

// }

void validateInputUsingCustomAtoLL(int64_t &var) {
    var = 0;
    char buffer[19] {};
    for(bool done {}; !done; ) {
        try
        {
            std::cout << "Please enter an integer value: ";
            std::cin >> buffer;
            TimeCounter t;
            // tested out and works faster than std::atoll also throws exception if it fails
            var = My::AtoLL(buffer);
            t.timedelta();

            done = true;
            std::cout << "value : " << var << "\n";
            
        } catch(const My::InvalidInputException& e) {
            clearConsoleInput();
        }
    }

}


int main()
{
    // size_t x {};
    int64_t value {};
    // setVarByInputAndValidate(x);
    // setVarByInputAndValidateSS(x);
    validateInputUsingCustomAtoLL(value);     // fastest validator
    

    return EXIT_SUCCESS;
}