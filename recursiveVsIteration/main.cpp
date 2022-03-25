#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

using timer = std::chrono::high_resolution_clock::time_point;   //type definition

int factorialWithRecursion(size_t n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorialWithRecursion(n - 1);
}

int factorialWithIteration(size_t n)
{
    size_t fact {1};
    for(size_t i {1}; i <= n; ++i)
        fact *= i;
    return fact;
}

int main()
{
    cout << "Enter a value for factorial : ";
    size_t val {};
    cin >> val;
    timer t1 {chrono::high_resolution_clock::now()};
    cout << "factorial of 5 with recursion is : " << factorialWithRecursion(val) << endl;
    timer t2 {chrono::high_resolution_clock::now()};
    cout << "factorial of 5 with iteration is : " << factorialWithIteration(val) << endl;
    timer t3 {chrono::high_resolution_clock::now()};
    chrono::duration <double> elapsed_time1 = duration_cast <chrono::duration<double>>(t2 - t1);
    cout << "elapsed time for recursion is : " << setprecision(10) << elapsed_time1.count() << " seconds" << endl;
    chrono::duration <double> elapsed_time2 = duration_cast <chrono::duration<double>>(t3 - t2);
    cout << "elapsed time for iteration is : " << setprecision(10) << elapsed_time2.count() << " seconds" << endl;
    return 0;
}