#include <iostream>
#include <limits>
#include <iomanip>
#include <bitset>
#include <cstdint>


namespace Custom {
    bool isInfinite(double val) {
        double sign {val < 0.0 ? -1.0: 1.0};
        return val * sign == 1.0/0.0;
    }

    // slower with -O0, faster with -Og
    size_t getSignByComparison(int64_t val) {
        return val < 0;
    }

    // faster with -O0, slower with -Og
    size_t getSignByBits(int64_t val) {
        return static_cast<uint64_t>(val) >> 63;
    }

    template <typename T>
    concept unsigned_type = !std::signed_integral<T>;

    template <typename T>
    concept signed_type = std::signed_integral<T>;

    // check signed int overflow or underflow
    template <signed_type T>
    bool isAdditionIntOverflow_Underflow(T val1, T val2) {
        if(val1 > 0 && val2 > std::numeric_limits<T>::max() - val1) { // overflow
            return true;
        } 
        if(val1 < 0 && val2 < std::numeric_limits<T>::min() - val1) { // underflow
            return true;
        }
        return false;
    }
    
    // check unsigned int overflow or underflow
    template <unsigned_type T>
    bool isAdditionU_IntOverflow_Underflow(T val1, T val2) {
        if(val1 + val2 < val1) {    //overflow
            return true;
        }

        if(val1 - val2 > val1) {    //underflow
            return true;
        }
        return false;
    }    
}

int main()
{
    uint32_t var {std::numeric_limits<uint32_t>::max()}, var2 {23};
    int64_t var3 {std::numeric_limits<int64_t>::min()}, var4 {-5};
    // std::bitset<64> var3Bits {(size_t)var3};
    // std::cout << "var3: " << var3 << ", " << var3Bits.to_string() << "\n"
    //           << "typecasted version of var3: " << static_cast<size_t>(var3) << "\n";
    
    if(Custom::isAdditionIntOverflow_Underflow(var3, var4)) {
        std::cout << "hit an overflow or underflow\n";
    }

    if(Custom::isAdditionU_IntOverflow_Underflow(var, var2)) {
        std::cout << "hit an overflow or underflow\n";
    }

    return EXIT_SUCCESS;
}