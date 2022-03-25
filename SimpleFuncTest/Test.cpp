#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using timePoint = std::chrono::high_resolution_clock::time_point;

void increment1(size_t &value);
void increment2(size_t &value);
void cube(double &value);
void multiplication(double &val1, double &val2, double &valResult);



int main()
{
    timePoint tp1 {chrono::high_resolution_clock::now()};
    size_t val1 {};
    size_t val2 {};
    // double valMultiplication {};
    
    increment1(val1);
    increment2(val2);
    // cube(val2);
    // multiplication(val1, val2, valMultiplication);

    cout << "increment1 val is now = " << val1 << endl;
    cout << "increment2 val is now = " << val2 << endl;

    timePoint tp2 {chrono::high_resolution_clock::now()};
    cout << "elapsed time is : " << std::chrono::duration_cast<chrono::duration<double>>(tp2 - tp1).count() << endl;

    return 0;
}

void increment1(size_t &value)
{
    for(size_t i {0}; i < 1'100'000'000; value += i++);
    //if you want to print thread id, just do the down below
}

void increment2(size_t &value)
{
    for(size_t i {0}; i < 1'100'000'000; value += i++);
    //if you want to print thread id, just do the down below
}

void cube(double &value)
{
    value *= value;
    value *= value;
    cout << "cube val is now = " << value << endl;
}

void multiplication(double &val1, double &val2, double &valResult)
{
    valResult = val1 * val2;
    cout << "multiplication val is = " << valResult << endl;
}

