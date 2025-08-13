#ifndef _BINARY_HPP_
#define _BINARY_HPP_

#include <iostream>
#include <bitset>
#include <cstring>

#define BITS_PER_BYTE 8
namespace Binary {
    std::string fromString(const std::string &str);
    std::string fromFloatingPointType(std::floating_point auto value);
    std::string fromIntegralType(std::integral auto value);
    bool checkIfLittleEndian();
}

// might cause UB use carefully
bool Binary::checkIfLittleEndian() {
    uint16_t val {0x1};
    // if the little part is being used first then machine is little endian
    if(*reinterpret_cast<uint8_t *>(&val) == 1)
        return true;
    return false;
}

std::string Binary::fromString(const std::string &str) {
    if(str.size() == 0)
        return {};
    std::string binaryForm {};
    binaryForm.resize(str.size() * (sizeof(uint8_t) * 8 + 1));
    // std::cout << "size: " << binaryForm.size() << "\n";
    // std::cout << "reserved mem: " << (str.size() * (sizeof(uint8_t) * 8 + 1)) << " bytes.\n";
    size_t size {};
    uint8_t ch;
    for(auto &&begin {str.begin()}, &&end {str.end()}; begin != end; ++begin) {
        ch = *begin;
        // more efficient than concatenation operator, almost 2x
        std::memcpy(&binaryForm.data()[size], std::bitset<sizeof(uint8_t) * 8> {ch}.to_string().data(), BITS_PER_BYTE);
        binaryForm[size + BITS_PER_BYTE] = ' ';
        size += BITS_PER_BYTE + 1;
    }
    binaryForm.pop_back();
    // std::cout << "size: " << binaryForm.size() << "\n";
    return binaryForm;
}

std::string Binary::fromFloatingPointType(std::floating_point auto value) {
    uint8_t *arr {reinterpret_cast<uint8_t *>(&value)};
    std::string binaryForm {};
    if(checkIfLittleEndian()) {
        for(uint8_t *offset {arr + sizeof(value) - 1}, *end {arr - 1}; offset != end; --offset) {
            // std::cout << "Address: " << static_cast<void *>(offset) << "\n";
            // slower than memcpy
            binaryForm += std::bitset<sizeof(uint8_t) * 8> {*offset}.to_string() + ' ';
        }
    } else {
        for(uint8_t *offset {arr}, *end {arr + sizeof(value)}; offset != end; ++offset) {
            // std::cout << "Address: " << static_cast<void *>(offset) << "\n";
            binaryForm += std::bitset<sizeof(uint8_t) * 8> {*offset}.to_string() + ' ';
        }
    }
    binaryForm.pop_back();
    return binaryForm;
}


std::string Binary::fromIntegralType(std::integral auto value) {
    return std::bitset<sizeof(value) * 8> {*reinterpret_cast<std::make_unsigned<decltype(value)>::type *>(&value)}.to_string();
}

#endif