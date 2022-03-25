/*this code written by Ali Fırat Özel */

#include <iostream>
#include <numbers>
#include <cmath>
#include <iomanip>
#include <chrono>

#define eps 1.0e-6  //higher precision higher execution time

using namespace std;
using std::numbers::e;

using timer = std::chrono::high_resolution_clock::time_point;

double fx(double x) //Burdan fonksiyonu tanımlıyorum
{
    return pow(e, -pow(x, 2));
}

//this function computes the integral of a function with bounds
double loopIntegral(double (*f)(double), double x_lower, double x_upper)   //fonksiyon pointer'ı kullanarak integral alıyor
{
    double val {0};
    for(double i {x_lower}; i < x_upper; i += ((x_upper - x_lower) * eps))
        val += f(i) * (x_upper - x_lower) * eps;
    return val;    
}

int main()
{
    double lower {-100}, upper {100};
    //kesinlik virgülden sonraki 5. basamakla azalıyor .4 doğru sonuç
    //yüksek kesinlik sisteme yük bindiriyor
    timer t1 {std::chrono::high_resolution_clock::now()};
    cout << "integral of e^(-x^2) with -100 - 100 boundaries : " << setprecision(11) << loopIntegral(*fx, lower, upper) << endl; 
    timer t2 {std::chrono::high_resolution_clock::now()};

    double elapsedTime {std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count()};
    cout << "elapsed time with loop integral : " << elapsedTime << endl;
    return 0;
}