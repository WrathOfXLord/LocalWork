#include <iostream>
#include "TestClass.hpp"

int main() {
    TestClass t1;
    TestClass t2 {345};
    int x = 3, y = 4;

    t1 += t2 + TestClass(23);
    TestClass t3 {t1 + t2};
    // std::cout << "Val: " << (t1 += t2) << "\n";
    std::cout << "Val: " << t1 << "\n";
    std::cout << "t3: " << t3 << "\n";

    std::cout << (x += y) + 3 << "\n";
    return 0;
}