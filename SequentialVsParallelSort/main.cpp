#include <iostream>
#include <execution>
#include <algorithm>
#include <random>
#include <chrono>
#include <print>

#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"
#include "../BLUEPRINTS/Sort/Sort.hpp"

int main()
{
    std::random_device rd;
    std::mt19937_64 mt {rd()};
    
    constexpr std::size_t VEC_SIZE {1'000'000};
    std::vector<double> doubleValues (VEC_SIZE);

    std::println("Testing with {} values", VEC_SIZE);

    // std::uniform_real_distribution<> dist {1.0, 1000000.0};
    for(auto &value: doubleValues) {
        value = static_cast<double>(mt());
    }

    constexpr std::size_t ITERATION_COUNT {5};
    TimeCounter t {};

    for(std::size_t iteration {}; iteration < ITERATION_COUNT; ++iteration) {
        std::vector<double> sorted {doubleValues};
        t.restart_timer();
        std::sort(std::execution::par_unseq, sorted.begin(), sorted.end());
        t.timedelta();
        std::println("Parallel Lowest: {}, Highest: {}", sorted[0], sorted[sorted.size() - 1]);
    }

    std::println();

    for(std::size_t iteration {}; iteration < ITERATION_COUNT; ++iteration) {
        std::vector<double> sorted {doubleValues};
        t.restart_timer();
        Sort::quicksort(sorted.data(), 0, sorted.size() - 1);
        t.timedelta();
        std::println("Custom Sort - Lowest: {}, Highest: {}", sorted[0], sorted[sorted.size() - 1]);
    }

    std::println();

    for(std::size_t iteration {}; iteration < ITERATION_COUNT; ++iteration) {
        std::vector<double> sorted {doubleValues};
        t.restart_timer();
        std::sort(sorted.begin(), sorted.end());
        t.timedelta();
        std::println("Serial Lowest: {}, Highest: {}", sorted[0], sorted[sorted.size() - 1]);
    }

    return EXIT_SUCCESS;
}