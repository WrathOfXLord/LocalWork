#include <iostream>
#include <chrono>

using timer = std::chrono::high_resolution_clock::time_point;


void printWithNewline();

int main()
{
    timer t1 {std::chrono::high_resolution_clock::now()};
    printWithNewline();
    timer t2 {std::chrono::high_resolution_clock::now()};
    
    std::chrono::duration<double> d1 {std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)};

    std::cout << "Newline test\n";
    std::cout << d1.count() << " seconds\n";    

    return 0;
}

void printWithNewline()
{
    for(size_t i {}; i < 25000; ++i)
        std::cout << i << '\n';
}
