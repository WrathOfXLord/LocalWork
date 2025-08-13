#include <iostream>
#include <bitset>
#include <functional>

namespace Custom {
    template <typename T>
    void testFunc(int number, const std::function<T /* return type */ (T /* parameter */)> &lambda) {
        T val {lambda(number)};
        std::cout << "val is: " << val << "\n";
    }
}


int main()
{
    // double number {-3.2};
    // constexpr const int BITS_PER_BYTE {8};
    // std::bitset<sizeof(double) * BITS_PER_BYTE> bitNumber {*reinterpret_cast<uint64_t *>(&number)};
    // std::cout << "number 1: " << bitNumber.to_string() << "\n";

    // std::cout << "sign bit of number: " << (*reinterpret_cast<uint64_t *>(&number) >> 63) << "\n";
    // std::cout << "number 1 casted: " << std::bitset<sizeof(double) * BITS_PER_BYTE> {*reinterpret_cast<uint64_t *>(&number)}.to_string() << "\n";

    // double number2 {7.2};
    // std::bitset<sizeof(double) * BITS_PER_BYTE> bitNumber2 {*reinterpret_cast<uint64_t *>(&number2)};
    // std::cout << "number 2: " << bitNumber2.to_string() << "\n";

    int val {32};
    Custom::testFunc<int>(val, [](int val) {
        return val * val + 3 * val + 5;
    });
    
    return EXIT_SUCCESS;
}