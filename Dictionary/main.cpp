#include <iostream>
#include <fstream>
#include "Dict.hpp"
#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"

template <typename Function>
auto ret(Function val) {
    return val();
}

int val() {
    return 3;
}

int main()
{
    // JsonValue v {32.0};
    // std::fstream file {"test.txt", std::ios::out | std::ios::app};
    // TimeCounter t {};
    // JsonValue f {v};

    // t.timedelta_in_nanos();
    // file.close();
    // std::cout << f.typeToC_Str() << "\n";

    int x = ret([]() {
        return 3;
    });

    std::cout << "x: " << x << "\n";

    return EXIT_SUCCESS;
}