#include <iostream>
#include <random>
#include <numeric>

#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"


int main(){
    std::cout << "Measuring time\n";
    
    constexpr std::size_t valueCount {1'000'000}; 
    std::vector<int> values;
    values.reserve(valueCount);

    TimeCounter t {};
    
    std::mt19937 generator {0};
    std::uniform_int_distribution<int> dist {0, 9};

    for(size_t i {}; i < valueCount; ++i) {
        values.emplace_back(dist(generator));
    }

    size_t sum {};

    sum = std::accumulate(values.begin(), values.end(), sum);
    t.timedelta();

    std::chrono::nanoseconds oneYear {31'557'000'000'000'000LL};
    std::cout << "year count: " << std::chrono::duration_cast<std::chrono::years>(oneYear).count() << "\n";

    std::cout << "sum: " << sum << "\n";
    
    return 0;
}