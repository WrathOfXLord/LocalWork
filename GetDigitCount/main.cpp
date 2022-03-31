#include <iostream>

uint64_t getDigitCount(int64_t number) {
    uint64_t count {};
    if(number < 0)
        number *= -1;
    uint64_t casted {static_cast<uint64_t>(number)};
    for(uint64_t base {1}; casted > base; ++count, base *= 10);
    
    return count;
}

int main() {
    std::cout << getDigitCount(12000000) << "\n";

    return EXIT_SUCCESS;
}