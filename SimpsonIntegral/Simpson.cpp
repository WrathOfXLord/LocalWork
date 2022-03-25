#include <iostream>
#include <numbers>
#include <cmath>
#include <iomanip>
#include <chrono>

using namespace std;
using std::numbers::e;

using timer = std::chrono::high_resolution_clock::time_point;

double fx(double x)
{
    return pow(e, -pow(x, 2));
}

double simpsonRule(double lower, double upper, int splitCount, double (*f)(double x))
{
    double stepSize {(upper - lower) / splitCount};
    double lowStep {lower}, upStep {lowStep + stepSize};
    double sum {0}; 
    for(double i {lower}; i <= upper - stepSize; i += stepSize)
    {
        sum += (f(lowStep) + 4 * f(lowStep + stepSize / 2) + f(upStep)) * stepSize / 6;
        lowStep += stepSize;
        upStep += stepSize;  

    }
    return sum;

}

int main()
{
    timer t1 {std::chrono::high_resolution_clock::now()};
    cout << "integral of e^(-x^2) with -100 - 100 boundaries : " << setprecision(11) << simpsonRule(-100, 100, 100'000, *fx) << endl;
    timer t2 {std::chrono::high_resolution_clock::now()};

    std::chrono::duration<double> elapsedTime {std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)};
    cout << "elapsed time with simpson 1/3 integral : " << elapsedTime.count() << " seconds.\n";
    return 0;
}