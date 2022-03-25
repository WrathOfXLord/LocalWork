#include "qsort.hpp"
#include <random>
#include <chrono>

template<typename type>
int64_t Sort<type>::randPivot(int64_t start, int64_t end)
{
    // random seed provided by time in seconds
    int64_t seed{std::chrono::steady_clock::now().time_since_epoch().count()};
    // mersenne twister 64 bit random engine
    std::mt19937_64 generator_engine{static_cast<size_t>(seed)};
    // uniform distribution
    std::uniform_int_distribution<int64_t> dist{start, end};
    return dist(generator_engine);
}

