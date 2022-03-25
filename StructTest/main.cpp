#include "TestStruct.hpp"
#include <iostream>


int main() {
    std::string_view arr[] {"hey", "there", "how are you", "fine u?"};
    const size_t arrSize {sizeof(arr)/sizeof(arr[0])};
    AnyStruct<arrSize> strct {"Test Struct", arr, arrSize};

    for(auto ite {strct.begin()}, iteEnd {strct.end()}; ite != iteEnd; ++ite) {
        std::cout << "value: " << *ite << "\n";
    }

    for(const auto &val:strct) {
        std::cout << "value: " << val << "\n";
    }

}