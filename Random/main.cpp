#include <iostream>
#include <chrono>
#include <random>

using tp = std::chrono::high_resolution_clock::time_point;

int main()
{
    //method 1      //recommended method if true rng is needed, but uses system entropy
    std::random_device seed;    //true random number generator, it may be more expensive than prng ones //overloads () operator.
    std::mt19937_64 rng {seed ()};  //Mersenne Twister 19937 random number generator
    std::uniform_int_distribution<int> distribute {1, 20};
    std::cout << "Checking random engine with loop (20 times)\n";
    for(size_t i {}; i != 20; ++i)
    {
        std::cout << distribute(rng);
        if(i + 1 != 20)
            std::cout << ", ";
    }

    //double one
    std::uniform_real_distribution<double> distribute2 {1, 20};
    std::cout << '\n';
    for(size_t i {}; i != 20; ++i)
    {
        std::cout << distribute2(rng);
        if(i + 1 != 20)
            std::cout << ", ";
    }

    //method 2  not recommended
    std::cout << "\n-------------------------------------------------------------------------------\n";
    std::random_device seed2;
    std::uniform_int_distribution<int> dist2 {1, 20};
    std::cout << "\nChecking other(2) random engine with loop (20 times)\n";
    for(size_t i {}; i != 20; ++i)
    {
        std::cout << dist2(seed2);
        if(i + 1 != 20)
            std::cout << ", ";
    }

    //method 3  recommended if pseudo rng is needed
    std::cout << "\n-------------------------------------------------------------------------------\n";
    tp timeNow {std::chrono::high_resolution_clock::now()};
    unsigned int seed3 = timeNow.time_since_epoch().count();
    std::uniform_int_distribution<int> dist3 {1, 20};
    std::cout << "\nChecking other(3) random engine with loop (20 times)\n";
    std::default_random_engine generate {seed3};
    for(size_t i {}; i != 20; ++i)
    {
        std::cout << dist3(generate);
        if(i + 1 != 20)
            std::cout << ", ";
    }    
    
    //method 4 faster prng
    
    std::uniform_real_distribution<double> dist4 {1, 20};
    std::cout << "\nChecking other(4) random engine with loop (20 times)\n";
    auto seed4 {std::chrono::high_resolution_clock::now().time_since_epoch().count()};  
    std::mt19937_64 rng2 (seed4);   //warning about narrowing from int to uint
    double x {};
    for(size_t i {}; i != 20; ++i)
    {
        x = dist3(rng2);
        std::cout << x;
        if(i + 1 != 20)
            std::cout << ", ";
    }    


    return 0;
}