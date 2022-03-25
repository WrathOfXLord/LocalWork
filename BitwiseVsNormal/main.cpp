#include <iostream>
#include <chrono>
#include <iomanip>

using time_point = std::chrono::high_resolution_clock::time_point;

int multiplyBy24Bitwise(int val)
{
    return (val << 4) + (val << 3);
}

int multiplyBy24Normal(int val)
{
    return val * 24;
}

int main()
{
    size_t val{1326467};
    size_t result {};
    std::cout << "computing...\n";
    time_point t1{std::chrono::high_resolution_clock::now()};
    for (size_t test{}; test < 1'000'000'000; ++test)
    {
        // bitwise
        // val = multiplyBy24Bitwise(val);
        // normal style
        result = multiplyBy24Bitwise(val);
    }

    time_point t2{std::chrono::high_resolution_clock::now()};
    std::cout << "value: " << result << " " << multiplyBy24Bitwise(val) << "\n";
    std::cout << "Elapsed time: " << std::setprecision(15) << std::fixed
              << std::chrono::duration<double>(std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)).count()
              << " seconds\n";
}