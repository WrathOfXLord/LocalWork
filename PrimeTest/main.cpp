#include <iostream>
#include <cmath>
#include "../BLUEPRINTS/timer_blueprint/TimeCounter.hpp"

bool isPrime(int64_t num) {
    for(int64_t index {2}; index < num; ++index) {
        if(num % index == 0) {
            return false;
        }
    }
    return true;
}

bool isPrimeV1(int64_t num) {
    // counter for debugging
    size_t counter {};
    for(int64_t index {2}, bound {num / 2}; index < bound; ++index, ++counter) {
        if(num % index == 0) {
            return false;
        }
    }
    return true;
}

bool isPrimeV2(int64_t num) {
    if(num == 2)
        return true;
    if(num % 2 == 0)
        return false;
    // counter for debugging
    size_t counter {};
    for(int64_t index {3}, bound {num / 2}; index < bound; index += 2, ++counter) {
        if(num % index == 0) {
            return false;
        }
    }
    return true;
}

bool isPrimeV3(int64_t num) {
    for(int64_t index {2}, bound {static_cast<int64_t>(std::sqrt(num) + 1)}; index < bound; ++index) {
        if(num % index == 0) {
            return false;
        }
    }
    return true;
}

// fastest way to find if a number is a prime
bool isPrimeV4(int64_t num) {
    if(num == 2)
        return true;
    if(num % 2 == 0)
        return false;
    for(int64_t index {3}, bound {static_cast<int64_t>(std::sqrt(num) + 1)}; index < bound; index += 2) {
        if(num % index == 0) {
            return false;
        }
    }
    return true;
}

#define PRIME 1000231

int main()
{
    TimeCounter t {};
    // bool primeCheck {isPrime(PRIME)};
    // bool primeCheck {isPrimeV1(PRIME)};
    bool primeCheck {isPrimeV2(PRIME)};
    // bool primeCheck {isPrimeV3(PRIME)};
    // bool primeCheck {isPrimeV4(PRIME)};
    t.timedelta();
    std::cout << "prime check: " << std::boolalpha << primeCheck << "\n";

    return EXIT_SUCCESS;
}