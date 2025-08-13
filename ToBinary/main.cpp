#include <iostream>
#include <iostream>
// #include <iomanip>
#include <limits>
#include <vector>
#include <cstring>

#include "../BLUEPRINTS/ToBinaryForm/Binary.hpp"
#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"

struct Point {
    int64_t x, y;

    Point(int64_t x, int64_t y)
    : x {x}, y {y} {
        std::cout << "simple constructor\n";
    }

    Point(const Point &ref) {
        std::cout << "copy constructor\n";
    }

    Point(Point &&ref) {
        std::cout << "move constructor\n";
    }

    ~Point() {
        std::cout << "destructor -- address: " << static_cast<void *>(this) << "\n";
    }
};

Point make_point(int x, int y) {
    if(x < y)
        return {x, y};
    return {y, x};
}


// void *operator new(size_t size) {
//     std::cout << "Allocated " << size << " bytes of memory.\n";
//     return std::malloc(size);
// }

// void operator delete(void *memory, size_t size) {
//     std::cout << "Released " << size << " bytes of memory.\n";
//     std::free(memory);
// }


int main() 
{
    // double val {1.0};
    // std::bitset<sizeof(double) * 8> bits {*reinterpret_cast<std::size_t *>(&val)};
    // std::cout << bits.to_string() << "\n";

    // std::cout << Binary::fromString("ALİ FIRAT ÖZEL") << "\n";
    // std::cout << Binary::fromFloatingPointType(-123.23) << "\n";
    // std::cout << Binary::fromIntegralType(-1) << "\n";

    // int32_t val {32};
    // std::printf("address: 0x%p\n", static_cast<void *>(&val));
    
    // std::cout << "long double sub norm min: " << std::numeric_limits<long double>::denorm_min() << "\n";

    // Point p {make_point(3, 4)};
    

    // double val {std::numeric_limits<double>::max() - 1};
    // std::cout << std::setprecision(60) << std::fixed << val << "\n";

    std::string name {"Test some value here qwerty asdfg heyyo what the hack whatİ"};
    std::cout << "name: " << name << "\n";
    TimeCounter t {};
    std::string binaryFormStr {Binary::fromString(name)};
    t.timedelta();
    std::cout << "--Binary Form--\n" << binaryFormStr << "\n";

    // std::string_view abc {"hello world! "};
    // std::string_view def {"how are you? "};
    // const size_t BUFFER_SIZE {abc.size() + def.size() + 1};
    // std::cout << "size1: " << BUFFER_SIZE << "\n";
    // std::string buffer {};
    // buffer.resize(BUFFER_SIZE);
    // TimeCounter t {};
    // char *ptr {buffer.data()};
    // std::memcpy(ptr, abc.data(), abc.size());
    // std::memcpy(&ptr[abc.size()], def.data(), def.size());
    // t.timedelta();
    // std::cout << buffer << "\n";


    return EXIT_SUCCESS;
}