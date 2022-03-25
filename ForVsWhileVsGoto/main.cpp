#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

using timer = std::chrono::high_resolution_clock::time_point;

size_t calculateSumByWhile(size_t startVal, size_t count);

size_t calculateSumByFor(size_t startVal, size_t count);

size_t calculateSumByGoTo(size_t startVal, size_t count);

int main()
{
    timer t1 {chrono::high_resolution_clock::now()};
    cout << "calculating by while : " << calculateSumByWhile(0, 3'000'000'000) << endl;
    timer t2 {chrono::high_resolution_clock::now()};
    cout << "calculating by for : " << calculateSumByFor(0, 3'000'000'000) << endl;
    timer t3 {chrono::high_resolution_clock::now()};
    cout << "calculating by goto : " << calculateSumByGoTo(0, 3'000'000'000) << endl;
    timer t4 {chrono::high_resolution_clock::now()};

    chrono::duration<double> elapsedTimeWhile {chrono::duration_cast<chrono::duration<double>>(t2 - t1)};
    chrono::duration<double> elapsedTimeFor {chrono::duration_cast<chrono::duration<double>>(t3 - t2)};
    chrono::duration<double> elapsedTimeGoto {chrono::duration_cast<chrono::duration<double>>(t4 - t3)};

    cout << "elapsed time with while : " << setprecision(12) << elapsedTimeWhile.count() << " seconds." << endl;
    cout << "elapsed time with for : " << setprecision(12) << elapsedTimeFor.count() << " seconds." << endl;
    cout << "elapsed time with goto : " << setprecision(12) << elapsedTimeGoto.count() << " seconds." << endl;
    return 0;
}

size_t calculateSumByWhile(size_t startVal, size_t count)
{
    size_t sum {0};
    {
        size_t i {startVal};
        while(i < count)
        {
            sum += i;
            ++i;
        }
    }
    return sum;
}

size_t calculateSumByFor(size_t startVal, size_t count)
{
    size_t sum {0};
    for(size_t i {startVal}; i < count; ++i)
        sum += i;
    
    return sum;
}

size_t calculateSumByGoTo(size_t startVal, size_t count)
{
    size_t sum {0};
    {
        size_t i {startVal};
        startLoop:
        if(i == count)
            goto endLoop;
            
        sum += i;
        ++i;
        goto startLoop;
    }
    endLoop:
    
    return sum;
}

