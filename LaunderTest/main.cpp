#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>
#include <format>
#include <typeinfo>

struct X { const int n; };
union U { X x; float f; }; 

int main() {

    alignas(int) char buffer[2 * sizeof(int)];
    int *p = new(buffer) int(42);
    std::cout << *p; 

    int *q = std::launder(p);
    std::cout << *q; // Geçerli çıktı: 42

    return 0;
}